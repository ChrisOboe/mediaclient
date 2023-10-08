#ifndef entry_h_INCLUDED
#define entry_h_INCLUDED

#include <QAbstractListModel>

class Entry{
    Q_GADGET
public:
    QString provider;
    QString id;
    QString channel;
    int number;
    QString name;
    QString description;
    QStringList tags;

    Q_PROPERTY(QString provider MEMBER provider)
    Q_PROPERTY(QString id MEMBER id)
    Q_PROPERTY(QString channel MEMBER channel)
    Q_PROPERTY(int number MEMBER number)
    Q_PROPERTY(QString name MEMBER name)
    Q_PROPERTY(QString description MEMBER description)
    Q_PROPERTY(QStringList tags MEMBER tags)
};

class EntryListModel : public QAbstractListModel {
    Q_OBJECT
public:
    enum Roles {
        ProviderRole = Qt::UserRole + 1,
        IdRole,
        ChannelRole,
        NumberRole,
        NameRole,
        DescriptionRole,
        TagsRole
    };

    explicit EntryListModel(QObject *parent = nullptr);

    int rowCount(const QModelIndex &parent = QModelIndex()) const override;
    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const override;
    QHash<int, QByteArray> roleNames() const override;

    void addEntry(const Entry &entry);
    void setEntries(const QList<Entry> &entries);
    void fromJson(const QByteArray& jsonData);

private:
    QList<Entry> m_entries;
};


#endif // entry_h_INCLUDED
