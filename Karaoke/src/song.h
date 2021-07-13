#ifndef SONG_H
#define SONG_H

#include <QString>

struct Song
{
    Song(QString country, QString band, QString songname, qint8 totalview);
    QString country;
    QString band;
    QString songname;
    qint8 totalview;
};

#endif
