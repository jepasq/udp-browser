#ifndef __WEB_TABLE_HPP__
#define __WEB_TABLE_HPP__

#include <QString>
#include <QStringList>

/** Defines an HTML table markup with header and elements
  *
  */
class WebTable
{
public:
  WebTable();

  QString toHtml();
  void    setHeaders(const QStringList&);

  void changeQuoteChar(char);
  
protected:
  QString openTag(const QString& tag, const QString& className="");
  QString closeTag(const QString& tag);
  
private:
  QStringList headers;  //!< The table headers
  QStringList items;    //!< The table content

  char QUOTE;   //!< The quote character. This is not a constant.
};

#endif // !__WEB_TABLE_HPP__
