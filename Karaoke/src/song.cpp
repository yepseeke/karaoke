#include "song.h"

Song::Song(QString language, QString singer, QString song, qint64 id, qint64 totalview)
{
    this->language = language;
    this->singer = singer;
    this->song = song;
    this->id = id;
    this->totalview = totalview;
}
