#ifndef __WEB_TABLE_HPP__
#define __WEB_TABLE_HPP__

#include <QString>
#include <QStringList>

/** Defines an HTTP table markup with header and elements
  *
  */
class WebTable
{
public:
  WebTable();

  QString ToHTML();

private:
  QStringList headers;
  QStringList items;
};

#endif // !__WEB_TABLE_HPP__
