// USBManager.cpp
#include "USBManager.h"
#include <QDebug>
#include <QFileInfo>

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

    // Assuming your USB drive is mounted at /media/username/USBDrive
    m_usbDrivePath = "/media/seame-workstation11/5EDB-55FB"; // Change this to your actual USB path

    QDir usbDir(m_usbDrivePath);
    if (usbDir.exists() && usbDir.isReadable()) {
        emit usbInserted();
    } else {
        qDebug() << "Failed to mount USB";
    }
    loadSongsFromUSB();
    // Emit the signal indicating that the file list has changed
    emit fileListChanged();

    qDebug() << "USB scan completed";
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
