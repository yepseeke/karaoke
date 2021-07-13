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
QString formDataFilePath();
void createDataPath();
Song convertJsonObjectToSong(QJsonObject &jsonObject);
QJsonObject convertSongToJsonObject(Song &song);
};

QString DWPrivate::formDataFilePath() {
    QDir dataDir(QStandardPaths::writableLocation(QStandardPaths::AppDataLocation));
    return dataDir.absoluteFilePath(QStringLiteral("data.json"));
}

void DWPrivate::createDataPath() {
    auto path = QStandardPaths::writableLocation(QStandardPaths::AppDataLocation);
    QDir directoryCreator;
    directoryCreator.mkpath(path);
}

QJsonObject DWPrivate::convertSongToJsonObject(Song &song){
    QJsonObject songObject;
    songObject["singer"] = song.singer;
    songObject["song"] = song.song;
    songObject["language"] = song.language;
    songObject["id"] = song.id;
    songObject["totalview"] = song.totalview;
    return songObject;
}

Song DWPrivate::convertJsonObjectToSong(QJsonObject &jsonObject) {
    return Song(
                  jsonObject["language"].toString(),
                jsonObject["singer"].toString(),
            jsonObject["song"].toString(),
            jsonObject["id"].toInt(),
            jsonObject["totalview"].toInt()
            );
}

QList<Song> DataWork::readData(QString path) {
//    QList<Song> songs = {Song("first1","first2","first3",10,0),Song("second1","second2","second3",2,0),
//                         Song("three1","three2","three3",3,0),Song("first1","first222","first3",4,0),
//                         Song("first1","first222","first4",5,0)};
    QList<Song> songs;
    if(path == " ") path = DWPrivate::formDataFilePath();
    qDebug() << "WAY" << path;
    QFile dataFile(path);
    if(!dataFile.exists()) {
        qDebug() << "WAY" << path;
        // Data does not exists
        return songs;
    }
    if(!dataFile.open(QFile::ReadOnly)) {
        // File could not be openned
        return songs;
    }

    auto rawData = dataFile.readAll();
    auto jsonDocument = QJsonDocument::fromJson(rawData);
    if(jsonDocument.isNull()) {
        // Data was not parsed
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
    DWPrivate::createDataPath();
    QFile dataFile(DWPrivate::formDataFilePath());
    dataFile.open(QFile::WriteOnly);
    if(dataFile.isOpen()) qDebug() <<"dadadadadadad";
    dataFile.write(jsonDocument.toJson(QJsonDocument::Indented));
    dataFile.close();
}
