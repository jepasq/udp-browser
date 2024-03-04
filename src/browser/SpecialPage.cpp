#include "SpecialPage.hpp"

#include <QDir>        // USES Qdir.absoluteFilePath()


SpecialPage::SpecialPage(QString u,  QUrl c):
  url(u),
  content(c)
{
  
}
  
const QString&
SpecialPage::getUrl() const
{
  return this->url;
}

const QUrl&
SpecialPage::getContent() const
{
  return this->content;
}

/// Set a local URL as content, relative to local media/ directory
void
SpecialPage::setMediaContent(const QString& u)
{
  QDir dir;
  QString uu = "../media/" + u + "/index.html";
  this->content =  QUrl::fromLocalFile(dir.absoluteFilePath(uu));
}


