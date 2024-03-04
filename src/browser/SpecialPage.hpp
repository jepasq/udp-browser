#ifndef __SPECIAL_PAGE_HPP__
#define __SPECIAL_PAGE_HPP__

#include <QString>
#include <QUrl>

/** A special page the user can access through a given URL
 *
 * Basically a string identifier (the URL you enter in the go lineedit
 * of the browser and the URL to the local content of the page)
 *
 */
class SpecialPage
{

public:
  SpecialPage(QString u, QUrl c = QUrl());
  
  const QString& getUrl() const;
  const QUrl&    getContent() const;

  void setMediaContent(const QString&);
  
private:
  QString url;     //!< The URL this page can be accessed with
  QUrl    content; //!< URL to local HTML content (may use QUrl::fromLocalFile)
  
};

#endif // !__SPECIAL_PAGE_HPP__
