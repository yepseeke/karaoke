#ifndef SONG_H
#define SONG_H

#include <QString>

struct Song
{
    Song(QString language, QString singer, QString song, qint64 id, qint64 totalview);
    QString language;
    QString singer;
    QString song;
    qint64 id;
    qint64 totalview;
};

#endif
