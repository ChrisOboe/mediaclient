#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QCommandLineParser>
#include <QUrl>
#include <QQmlContext>
#include "mediaclient.h"
#include "mpvobject.h"
#include "entry.h"

int main(int argc, char *argv[]) {
    QCoreApplication::setOrganizationName("mediaclient");
    QCoreApplication::setApplicationName("mediaclient");
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
    QCoreApplication::setAttribute(Qt::AA_ShareOpenGLContexts);

    //if (argc != 2 ) {
    //    return 1;
    //};

    //QUrl url(argv[1]);

    QGuiApplication app(argc, argv);
    // Qt sets the locale in the QGuiApplication constructor, but libmpv
    // requires the LC_NUMERIC category to be set to "C", so change it back.
    std::setlocale(LC_NUMERIC, "C");

    QQmlApplicationEngine engine;

	qmlRegisterType<MpvObject>("mpv", 1, 0, "MpvObject");

    EntryListModel elm;
    Mediaclient m("http://localhost:8080", &elm);

    engine.rootContext()->setContextProperty("entriesModel", &elm);

    engine.load(QUrl(QStringLiteral("qrc:main.qml")));
    return app.exec();
}
