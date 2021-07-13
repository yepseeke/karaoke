#include <algorithm>
#include <QVariant>
#include <QDebug>
#include "datawork.h"
#include "filter.h"

Filter::Filter(QObject* parent) : QAbstractListModel(parent), m_elements()
{

}

QHash<int, QByteArray> Filter::roleNames() const {
    QHash<int, QByteArray> roles;
    roles[ElemRole] = "element";
    roles[KeyRole] = "key";
    return roles;
}

QVariant Filter::data(const QModelIndex &index, int role) const {
    if(!index.isValid())
        return QVariant();
    switch(role) {
    case ElemRole:
        return QVariant(m_elements[index.row()]);
    case KeyRole:
        return QVariant(key);
    default:
        return QVariant();
    }
}
void Filter::getLanguages() {
    QList<Song> cur = DataWork::readData();
    beginResetModel();
    for (auto it = cur.begin(); it != cur.end(); ++it)
        m_elements.append(it->country);
    m_elements.removeDuplicates();
    endResetModel();
}

void Filter::getBands(QString language){
    QList<Song> cur = DataWork::readData();
    beginResetModel();
    m_elements.clear();
    for (auto it = cur.begin(); it != cur.end(); ++it)
        if(it->country==language)
            m_elements.append(it->band);
    m_elements.removeDuplicates();
    endResetModel();
}

