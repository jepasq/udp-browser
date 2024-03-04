#include "SpecialPage.hpp"

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

