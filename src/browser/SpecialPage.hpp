#ifndef __SPECIAL_PAGE_HPP__
#define __SPECIAL_PAGE_HPP__

#include <QString>
#include <QUrl>

/** A special page the user can access through a given URL
 *
 * Basically a string identifier (the URL you enter in the go lineedit
 * of the browser and the URL to the local content of the page)
 *
 * There's also a dynamic data step you must call before displaying called
 * process.
 *
 * To make the rendered HTML table easier to read, two fields containing name
 * and comment were added.
 *
 */
class SpecialPage
{

public:
  SpecialPage();
  SpecialPage(QString u, QUrl c = QUrl());
  
  const QString& getUrl() const;
  const QUrl&    getContentText() const;

  void setMediaContent(const QString&);

  virtual QString process();

  void           setName(const QString&);
  const QString& getName(void) const;

  void           setComment(const QString&);
  const QString& getComment(void) const;

protected:
  QString replaceText(const QString &, const QString &);
  
private:
  QString name;    //!< The current page name
  QString comment; //!< An additional comment field
  
  QString url;     //!< The URL this page can be accessed with
  QUrl    content; //!< URL to local HTML content (may use QUrl::fromLocalFile)
  
};

#endif // !__SPECIAL_PAGE_HPP__
