#ifndef FILTR_H
#define FILTR_H

#include <QAbstractListModel>
#include <QList>
#include "song.h"
#include "songlist.h"


class Filter : public QAbstractListModel
{
    Q_OBJECT
public:
    explicit Filter(QObject *parent = nullptr);

    enum FiltrRoles {
        ElemRole = Qt::UserRole + 1,
        KeyRole
    };
    virtual int rowCount(const QModelIndex&) const { return m_elements.size(); }
    virtual QVariant data(const QModelIndex &index, int role) const;
    QHash<int, QByteArray> roleNames() const;

    Q_INVOKABLE void setKey(QString cur){key = cur;}
    Q_INVOKABLE QString getKey(){return key;}
    Q_INVOKABLE void getLanguages();
    Q_INVOKABLE void getBands(QString);
private:
    QList<QString> m_elements;
    QString key;
};

#endif // FILTR_H
