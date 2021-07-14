#ifndef DATAWORK_H
#define DATAWORK_H

#include <QList>
#include <QMap>
#include <QString>
#include "song.h"

namespace DataWork {
    QList<Song> readData(QString);
    //QList<
    void storeData(QList<Song> &songs);
};

#endif // DATAWORK_H
