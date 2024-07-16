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
  
private:
  QStringList headers;  //!< The table headers
  QStringList items;    //!< The table content
};

#endif // !__WEB_TABLE_HPP__
