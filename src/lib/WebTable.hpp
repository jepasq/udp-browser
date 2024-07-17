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

  void setHeaders(const QStringList&);
  void setItems(const QStringList&);
  void appendItem(const QString&);
  void appendItems(const QStringList&);

  void changeQuoteChar(char);
  
  QString toHtml();
  
protected:
  QString openTag(const QString& tag, const QString& className="");
  QString closeTag(const QString& tag);
  
private:
  QStringList headers;  //!< The table headers
  QStringList items;    //!< The table content

  /** The quote character tat enclose strings in HTML markup.
    * This is not a constant.
    *
    */
  char QUOTE;   
};

#endif // !__WEB_TABLE_HPP__
