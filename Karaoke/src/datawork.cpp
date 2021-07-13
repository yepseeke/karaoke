#include <QDir>
#include <QDebug>
#include <QFile>
#include <QJsonArray>
#include <QJsonDocument>
#include <QJsonObject>
#include <QStandardPaths>

#include "datawork.h"
#include "song.h"

namespace DWPrivate {
Song convertJsonObjectToSong(QJsonObject &jsonObject);
QJsonObject convertSongToJsonObject(Song &song);
};

QJsonObject DWPrivate::convertSongToJsonObject(Song &song){
    QJsonObject songObject;
    songObject["singer"] = song.band;
    songObject["song"] = song.songname;
    songObject["language"] = song.country;
    return songObject;
}

Song DWPrivate::convertJsonObjectToSong(QJsonObject &jsonObject) {
    return Song(
                jsonObject["singer"].toString(),
                jsonObject["song"].toString(),
                jsonObject["language"].toString(),
                jsonObject["id"].toInt()
            );
}

QList<Song> DataWork::readData() {
    QList<Song> songs /*= {Song("first1","first2","first3",10),Song("second1","second2","second3",2),
                         Song("three1","three2","three3",3),Song("first1","first222","first3",4),
                         Song("first1","first222","first4",5)}*/;

    //QFile dataFile("");
    QFile dataFile("/home/defaultuser/karaoke/base-all.json");
    if(!dataFile.exists()) {
        // Data does not exists
        qDebug() << "Data file path: "<<QDir::currentPath();
        return songs;
    }
    if(dataFile.exists()) {
        qDebug() << "Data exist "<<QDir::currentPath();
    }
    if(!dataFile.open(QFile::ReadOnly)) {
        // File could not be openned
        qDebug() << "Data is open "<<QDir::currentPath();
        return songs;
    }

    auto rawData = dataFile.readAll();
    qDebug() << rawData;
    QJsonParseError error;
    auto jsonDocument = QJsonDocument::fromJson(rawData, &error);
    if(jsonDocument.isNull()) {
        // Data was not parsed
        qDebug() << "Data was not parsed: "<< error.errorString();
        return songs;
    }
    if(!jsonDocument.isArray()) {
        // Root element is not array
        return songs;
    }
    auto jsonArray = jsonDocument.array();
    foreach(QJsonValue arrayValue, jsonArray) {
        if(!arrayValue.isObject()) continue; // Element of the array is not an object
        auto jsonObject = arrayValue.toObject();
        songs.append(DWPrivate::convertJsonObjectToSong(jsonObject));
    }
    return songs;
}

void DataWork::storeData(QList<Song> &songs){
    QJsonArray jsonArray;
    foreach(Song song, songs){
        jsonArray.append(DWPrivate::convertSongToJsonObject(song));
    }
    QJsonDocument jsonDocument;
    jsonDocument.setArray(jsonArray);
    QFile dataFile("/home/defaultuser/karaoke/base.json");
    dataFile.open(QFile::WriteOnly);
    dataFile.write(jsonDocument.toJson(QJsonDocument::Indented));
    dataFile.close();
}
