
#define USBMANAGER_H

#include <QObject>
#include <QFileSystemWatcher>
#include <QStringList>
#include <QDir>
class USBManager : public QObject
{
    Q_OBJECT

public:
    USBManager(QObject *parent = nullptr);



signals:
    void usbInserted();
    void usbRemoved();
    void mp3FilesChanged(const QStringList &mp3Files);
    void usbDevicePathChanged(const QString &usbDevicePath);

private slots:
    void handleDirectoryChange(const QString &path);
    void startCheckingForUSB();

private:
    QFileSystemWatcher usbWatcher;
    QStringList mp3Files;
    QString usbDirPath;


    void findUSBDevicePath();
    QStringList findMusicFiles(const QDir &directory, const QStringList &filters);
    bool isUSBMounted(const QString &path);
    void loadMP3Files(const QString &usbPath);
};
