/** @file %{Cpp:License:FileName}
 *
 * The %{Cpp:License:ClassName} class
 *
 * $Author$
 * $Date$
 * $Rev$
 *
 * Copyright Saifas LLC 2019. All rights reserved.
 */
#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>
#include <QStandardPaths>
#include <QDir>

#include "mymediaplayer.h"

int main(int argc, char *argv[])
{
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);

    QGuiApplication app(argc, argv);

    QQmlApplicationEngine engine;

    MyMediaPlayer player;
    engine.rootContext()->setContextProperty("mediaplayer", &player);

    const QUrl url(QStringLiteral("qrc:/main.qml"));
    QObject::connect(&engine, &QQmlApplicationEngine::objectCreated,
                     &app, [url](QObject *obj, const QUrl &objUrl) {
        if (!obj && url == objUrl)
            QCoreApplication::exit(-1);
    }, Qt::QueuedConnection);
    engine.load(url);

    QString fileName = "SampleVideo_360x240_30mb.mp4";
    auto filePath = QStandardPaths::locate(QStandardPaths::MoviesLocation, fileName);
    player.setMedia(QUrl::fromLocalFile(filePath));

    return app.exec();
}
