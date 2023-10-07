#ifndef browser_h_INCLUDED
#define browser_h_INCLUDED

#include <QObject>
#include <QString>

class Mediaclient : public QObject {
    Q_OBJECT
    Q_PROPERTY(QString url READ url NOTIFY urlChanged)

    public:
        Mediaclient(QString url, QObject *parent = nullptr);
        QString url();
        QString session();

    signals:
        void urlChanged(QString url);

    private:
        QString m_url;
};

#endif // browser_h_INCLUDED
