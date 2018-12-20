#include <QCoreApplication>
#include <QDir>
#include <QDebug>
#include "watcher.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    Watcher w;
    w.setFile(QDir::currentPath() + QDir::separator() + "test.txt");

    return a.exec();
}
