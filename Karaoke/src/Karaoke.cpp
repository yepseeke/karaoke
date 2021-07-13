#include <sailfishapp.h>
#include <QtQuick>
#include "songlist.h"
#include "filter.h"

int main(int argc, char *argv[])
{
    qmlRegisterType<SongList>("Karaoke", 1, 0, "SongList");
    qmlRegisterType<Filter> ("Karaoke", 1, 0, "Filter");
    // SailfishApp::main() will display "qml/%ProjectName%.qml", if you need more
    // control over initialization, you can use:
    //
    //   - SailfishApp::application(int, char *[]) to get the QGuiApplication *
    //   - SailfishApp::createView() to get a new QQuickView * instance
    //   - SailfishApp::pathTo(QString) to get a QUrl to a resource file
    //   - SailfishApp::pathToMainQml() to get a QUrl to the main QML file
    //
    // To display the view, call "show()" (will show fullscreen on device).

    return SailfishApp::main(argc, argv);
}
