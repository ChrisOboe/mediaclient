#include "entry.h"
#include <QJsonDocument>
#include <QJsonArray>
#include <QJsonObject>
#include <QJsonValue>

EntryListModel::EntryListModel(QObject *parent)
    : QAbstractListModel(parent) {}

int EntryListModel::rowCount(const QModelIndex &parent) const {
    Q_UNUSED(parent)
    return m_entries.count();
}

QVariant EntryListModel::data(const QModelIndex &index, int role) const {
    if (index.row() < 0 || index.row() >= m_entries.count())
        return QVariant();

    const Entry &entry = m_entries[index.row()];
    switch (role) {
        case ProviderRole: return entry.provider;
        case IdRole: return entry.id;
        case ChannelRole: return entry.channel;
        case NumberRole: return entry.number;
        case NameRole: return entry.name;
        case DescriptionRole: return entry.description;
        case TagsRole: return entry.tags;
    }
    return QVariant();
}

QHash<int, QByteArray> EntryListModel::roleNames() const {
    QHash<int, QByteArray> roles;
    roles[ProviderRole] = "provider";
    roles[IdRole] = "id";
    roles[ChannelRole] = "channel";
    roles[NumberRole] = "number";
    roles[NameRole] = "name";
    roles[DescriptionRole] = "description";
    roles[TagsRole] = "tags";
    return roles;
}

void EntryListModel::addEntry(const Entry &entry) {
    beginInsertRows(QModelIndex(), m_entries.count(), m_entries.count());
    m_entries.append(entry);
    endInsertRows();
}

void EntryListModel::setEntries(const QList<Entry> &entries) {
    beginResetModel();
    m_entries = entries;
    endResetModel();
}

void EntryListModel::fromJson(const QByteArray &jsonData) {
    QJsonDocument doc = QJsonDocument::fromJson(jsonData);
    if (!doc.isArray()) {
        qDebug() << "JSON is not an array";
        return;
    }

    QJsonArray array = doc.array();
    QList<Entry> entries;

    for (const QJsonValue &value : array) {
        if (!value.isObject()) continue;

        Entry entry;
        QJsonObject obj = value.toObject();

        entry.provider = obj["provider"].toString();
        entry.id = obj["id"].toString();
        entry.channel = obj["channel"].toString();
        entry.number = obj["number"].toInt();
        entry.name = obj["name"].toString();
        entry.description = obj["description"].toString();
        entry.tags = obj["tags"].toVariant().toStringList();

        entries.append(entry);
    }

    setEntries(entries);
}

