#ifndef WATCHER_H
#define WATCHER_H

#include <QObject>
#include <QDebug>
#include <QTimer>
#include <QFileInfo>
#include <QDir>
#include <QDateTime>

class Watcher : public QObject
{
    Q_OBJECT
public:
    explicit Watcher(QObject *parent = nullptr);

    void setFile(QString file);

signals:

public slots:
private slots:
    void timeout();

private:
    QTimer timer;
    QString path;
    QDateTime modified;
    bool exists;
};

#endif // WATCHER_H
