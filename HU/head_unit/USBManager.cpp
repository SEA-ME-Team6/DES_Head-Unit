
#include "USBManager.h"
#include <QQmlEngine>
#include <QDir>
#include <QDebug>
#include <QStorageInfo>
#include <QQmlContext>



USBManager::USBManager(QObject *parent)
    : QObject(parent)
{


    usbWatcher.addPath("D:/");
    connect(&usbWatcher, &QFileSystemWatcher::directoryChanged, this, &USBManager::handleDirectoryChange);

    startCheckingForUSB();
}


void USBManager::startCheckingForUSB()
{
    QDir usbRootDir("D:/");

    if (usbRootDir.exists()) {
        QStringList usbSubDirs = usbRootDir.entryList(QDir::Dirs | QDir::NoDotAndDotDot);

        for (const QString &subDir : usbSubDirs) {
            usbDirPath = "D:/" + subDir;

            if (isUSBMounted(usbDirPath)) {
                qDebug() << "send signal";

                emit usbInserted();





            }
        }
    }


}



void USBManager::handleDirectoryChange(const QString &path)
{
    qDebug() << "handle Directory Changed!";

    QDir usbRootDir(path);

    if (usbRootDir.exists()) {
        QStringList usbSubDirs = usbRootDir.entryList(QDir::Dirs | QDir::NoDotAndDotDot);

        for (const QString &subDir : usbSubDirs) {
            usbDirPath = "D:/" + subDir;
        }
    }

    qDebug() << "path2: " << usbDirPath;

    QDir usbDir(usbDirPath);

    if(usbDir.exists()) {
        emit usbInserted();
        emit usbDevicePathChanged(usbDirPath);
        loadMP3Files(usbDirPath);
    } else {
        emit usbRemoved();
    }
}

bool USBManager::isUSBMounted(const QString &path)
{
    QFileInfo fileInfo(path);
    return fileInfo.isDir() && fileInfo.isWritable();
}
QStringList USBManager::findMusicFiles(const QDir &directory, const QStringList &filters)
{
    QStringList musicFiles;

    if (directory.exists()) {
        QStringList allFiles = directory.entryList(filters, QDir::Files);

        for (const QString &fileName : allFiles) {
            QString filePath = directory.filePath(fileName);
            musicFiles.append(filePath);
        }
    }

    return musicFiles;
}
void USBManager::loadMP3Files(const QString &usbPath)
{
    QDir usbDir(usbPath);
    QStringList filters;
    filters << "*.mp3" << "*.wav" << "*.ogg" << "*.flac"; // Add more formats if needed
    mp3Files = findMusicFiles(usbDir, filters);

    emit mp3FilesChanged(mp3Files);
    qDebug() << "MP3 files loaded: " << mp3Files;
}



