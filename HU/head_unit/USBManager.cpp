// USBManager.cpp
#include "USBManager.h"
#include <QDebug>
#include <QFileInfo>
#include <QStorageInfo>

USBManager::USBManager(QObject *parent) : QObject(parent)
{
    connect(this, &USBManager::usbInserted, this, &USBManager::loadSongsFromUSB);
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

            // Emit the signal indicating that the file list has changed
            emit fileListChanged();

            qDebug() << "USB scan completed";
            return; // Stop scanning once a USB drive is found
        }
    }

    qDebug() << "No USB drive found";
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
