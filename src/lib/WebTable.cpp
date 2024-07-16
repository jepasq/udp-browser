#include "WebTable.hpp"

#include <iostream>

WebTable::WebTable(): QUOTE('\'')
{

}

/// Will be used with SpecialPage::replaceText as QString
QString
WebTable::toHtml()
{
  // Basic structure from https://getbootstrap.com/docs/4.0/content/tables/
  QString content = openTag("thead") + openTag("tr");

  for (auto h : headers)
    content += openTag("th") + h + closeTag("th");
    
  content += closeTag("tr") + closeTag("thead");
  content += openTag("tbody");

  // Number of cols/rows
  auto nbcols = headers.length();
  auto nbrows = items.length() / nbcols;
  // Must add items...
  
  
  content += closeTag("tbody");

  
  return "<table>" + content + "</table>";
}

void
WebTable::setHeaders(const QStringList& sl)
{
  headers = sl;
}

QString
WebTable::openTag(const QString& tag, const QString& className)
{
  if (className.isEmpty())
    return QString("<" + tag + ">");

  return QString("<" + tag + " class=" + QUOTE + className + QUOTE + ">");
}

QString 
WebTable::closeTag(const QString& tag)
{
  return QString("</" + tag + ">");
}

void
WebTable::changeQuoteChar(char c)
{
  QUOTE = c;
}

void
WebTable::setItems(const QStringList& i)
{
  items = i;
}
