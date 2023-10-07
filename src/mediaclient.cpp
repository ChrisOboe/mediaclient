#include "mediaclient.h"
#include <QUrl>
#include <QDebug>

Mediaclient::Mediaclient(QString url, QObject* parent) : QObject(parent) {
  m_url = url;
}

QString Mediaclient::url(){
  qDebug() << "url:" << m_url;
  return m_url;
}
