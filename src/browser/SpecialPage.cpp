#include "SpecialPage.hpp"

#include <QDir>        // USES Qdir.absoluteFilePath()

#include <QFile>
#include <QTextStream>

/** Sopecial page constructor
 *
 * If you need to set a local URL as URL member (c parameter), you'd better
 * use the setMediaContent() function.
 *
 * \param u The URL string identifier
 * \param c The content URL
 *
 */
SpecialPage::SpecialPage(QString u,  QUrl c):
  url(u),
  content(c)
{
  
}

/** Get the URL member
 *
 * \return The URL as a Qt string type.
 *
 */
const QString&
SpecialPage::getUrl() const
{
  return this->url;
}

/** Get the URL we can find the content to
 *
 * It is often a local URL.
 *
 * \return The URL to the content.
 *
 */
const QUrl&
SpecialPage::getContentText() const
{
  return this->content;
}

/** Set a local URL as content, relative to local media/ directory
  *
  * \param u Where ../media/" + u + "/index.html is the URL.
  *
  */
void
SpecialPage::setMediaContent(const QString& u)
{
  QDir dir("../media/" + u + "/index.html");
  this->content =  QUrl::fromLocalFile(dir.canonicalPath());
}

/** The special step needed to place dynamic data before displaying it
  *
  * Just here, empty, so we can instantiate temporary special pages.
  *
  */
QString
SpecialPage::process()
{

}

/** Replace a with b in the processed text
  *
  * Used by subclasses to replace template text such as {{TEXT}}.
  *
  */
QString
SpecialPage::replaceText(const QString& a, const QString& b)
{
  auto contentUrl = this->content;

  // We assume it's a local URL
  QFile f(contentUrl.toString());
  if (!f.open(QFile::ReadOnly | QFile::Text))
    {
      std::string msg = "Opening file '" + contentUrl.toString().toStdString()
	+ "' failed!";
      throw std::runtime_error(msg);
    }
  QTextStream in(&f);
  auto txt = in.readAll();
  
  // txt should be the test page content
  txt.replace(a, b);
  return QString(txt);
}
