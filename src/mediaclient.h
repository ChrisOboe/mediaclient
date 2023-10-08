#ifndef browser_h_INCLUDED
#define browser_h_INCLUDED

#include <QObject>
#include <QString>
#include <QNetworkAccessManager>
#include "entry.h"

class Mediaclient : public QObject {
    Q_OBJECT
    Q_PROPERTY(QString url READ url NOTIFY urlChanged)

    public:
        Mediaclient(QString url, EntryListModel* elm, QObject *parent = nullptr);
        QString url();

    signals:
        void urlChanged(QString url);

    private:
        QNetworkAccessManager* m_nam;
        QString m_url;
        EntryListModel* m_elm;
};

#endif // browser_h_INCLUDED
