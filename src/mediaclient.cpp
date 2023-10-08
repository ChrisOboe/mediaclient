#include "mediaclient.h"
#include <QUrl>
#include <QDebug>
#include <QNetworkAccessManager>
#include <QNetworkRequest>
#include <QNetworkReply>

Mediaclient::Mediaclient(QString url, EntryListModel* elm, QObject* parent) : QObject(parent) {
  m_url = url;
  m_elm = elm;
  m_nam = new QNetworkAccessManager();

  QUrl requestUrl{QString("%1/entries").arg(m_url)};

  auto* reply = m_nam->get(QNetworkRequest(requestUrl));
  connect(reply, &QNetworkReply::finished, this, [this,reply]() {
      if (reply->error()) {
          qDebug() << reply->errorString();
          return;
      }
      QByteArray answer = reply->readAll();
      reply->deleteLater();

      m_elm->fromJson(answer);
  });
}

QString Mediaclient::url(){
  qDebug() << "url:" << m_url;
  return m_url;
}
