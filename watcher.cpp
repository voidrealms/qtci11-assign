#include "watcher.h"

Watcher::Watcher(QObject *parent) : QObject(parent)
{

    exists = false;
    modified = QDateTime::currentDateTime();

    timer.setInterval(500);
    connect(&timer,&QTimer::timeout, this, &Watcher::timeout);
    timer.start();
}

void Watcher::setFile(QString file)
{
    path = file;
    QFileInfo fi(path);
    exists = fi.exists();
    modified = fi.lastModified();
}

void Watcher::timeout()
{
    QFileInfo fi(path);
    QString current = QTime::currentTime().toString(Qt::DateFormat::SystemLocaleLongDate);

    if(fi.exists()) {
        if(!exists) qInfo() << "Created: " << current;
        if(modified != fi.lastModified()) qInfo() << "Modified: " << current;
        exists = true;
        modified = fi.lastModified();
    } else {
        if(exists) qInfo() << "Deleted: " << current;
        exists = false;
        modified = QDateTime::currentDateTime();
    }
}
