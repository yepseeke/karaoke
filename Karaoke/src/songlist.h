#ifndef SONGLIST_H
#define SONGLIST_H

#include <QAbstractListModel>
#include <QList>
#include "song.h"


class SongList : public QAbstractListModel
{
    Q_OBJECT
public:
    explicit SongList(QObject *parent = nullptr);

    enum SongRoles {
        CountryRole = Qt::UserRole + 1,
        BandRole,
        SongnameRole,
        TotalviewRole
    };
    virtual int rowCount(const QModelIndex&) const { return m_songs.size(); }
    virtual QVariant data(const QModelIndex &index, int role) const;
    QHash<int, QByteArray> roleNames() const;

    friend bool cmp(const Song& s1,const Song& s2);
    Q_INVOKABLE void sortList();
    Q_INVOKABLE void readList();
    Q_INVOKABLE void storeList();
    Q_INVOKABLE void getSongList(QString, QString);
    Q_INVOKABLE void findelemList(QString, QString, QString, qint8);
private:
    QList<Song> m_songs;
};

#endif // SONGLIST_H
