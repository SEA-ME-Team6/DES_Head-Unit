// USBManager.cpp
#include "USBManager.h"
#include <QDebug>
#include <QFileInfo>
#include <QStorageInfo>
#include <QProcess>

USBManager::USBManager(QObject *parent) : QObject(parent)
{
    connect(this, &USBManager::usbInserted, this, &USBManager::loadSongsFromUSB);
    connect(this, &USBManager::usbInserted, this, &USBManager::mountUSB);
    // Connect more signals as needed
}
QStringList USBManager::fileList() const
{
    return m_fileList;
}
void USBManager::startUSBScan()
{
    qDebug() << "USB scan initiated";

    // Get a list of available storage devices
    QList<QStorageInfo> drives = QStorageInfo::mountedVolumes();

    // Check each drive for a USB drive
    for (const QStorageInfo &drive : drives) {
        if (drive.isValid() && drive.isReady() && drive.device().startsWith("/dev/sd")) {
            m_usbDrivePath = drive.rootPath();
            emit usbInserted();
            mountUSB();
            // Emit the signal indicating that the file list has changed
            emit fileListChanged();

            qDebug() << "USB scan completed";
            return; // Stop scanning once a USB drive is found
        }
    }

    qDebug() << "No USB drive found";
}

void USBManager::mountUSB()
{
    // Mount the USB drive using a system command
    QString mountCommand = "udisksctl mount -b /dev/sda1";  // Replace /dev/sdX with the appropriate device name for your USB drive
    QProcess process;
    QStringList arguments = mountCommand.split(' ', Qt::SkipEmptyParts);
    QString program = arguments.takeFirst();  // Extract the program (udisksctl in this case)
    process.start(program, arguments);

    process.waitForFinished();

    if (process.exitCode() == 0) {
        qDebug() << "USB drive mounted successfully";
        emit usbInserted();

        // Emit the signal indicating that the file list has changed
        emit fileListChanged();
    } else {
        qDebug() << "Failed to mount USB drive";
        qDebug() << "Standard Output:" << process.readAllStandardOutput();
        qDebug() << "Standard Error:" << process.readAllStandardError();

    }
}

bool USBManager::isUSBDriveMounted()
{
    // Check if the USB drive is already mounted
    QProcess process;
    process.start("udisksctl", QStringList() << "info" << "-b" << "/dev/sda1");  // Replace /dev/sdX with the appropriate device name for your USB drive
    process.waitForFinished();

    // If the exit code is 0, the device is mounted; otherwise, it is not
    return process.exitCode() == 0;
}


void USBManager::loadSongsFromUSB()
{
    m_fileList.clear();

    QDir usbDir(m_usbDrivePath);
    QStringList nameFilters;
    nameFilters << "*.mp3";

    QStringList files = usbDir.entryList(nameFilters, QDir::Files | QDir::NoDotAndDotDot);
    for (const QString &file : files) {
        QFileInfo fileInfo(usbDir.filePath(file));
        m_fileList.append(fileInfo.absoluteFilePath());
    }

    qDebug() << "File list loaded from USB:" << m_fileList;


    // You can perform further actions with the loaded file list
}
