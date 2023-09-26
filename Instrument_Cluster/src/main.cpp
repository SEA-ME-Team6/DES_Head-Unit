#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>
#include "GearSelectionClient.hpp"
#include "SpeedStatusClient.hpp"

int main(int argc, char *argv[])
{

    QGuiApplication app(argc, argv);

    GearSelectionClient *gearclient = new GearSelectionClient();
    gearclient->run();

    SpeedStatusClient *speedclient = new SpeedStatusClient();
    speedclient->run();


    QQmlApplicationEngine engine;
    engine.rootContext()->setContextProperty("client", gearclient);

    const QUrl url(QStringLiteral("qrc:/main.qml"));
    QObject::connect(&engine, &QQmlApplicationEngine::objectCreated,
        &app, [url](QObject *obj, const QUrl &objUrl) {
            if (!obj && url == objUrl)
                QCoreApplication::exit(-1);
        }, Qt::QueuedConnection);
    engine.load(url);


    return app.exec();
}