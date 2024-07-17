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

  content += openTag("tr");

  // Must add items...
  auto itemsByRow = 1;
  for (auto i : items)
    {
      content += openTag("td");
      content += i;
      content += closeTag("td");
      itemsByRow++;

      if (itemsByRow > nbcols)
	{
	  content += closeTag("tr");
	  content += openTag("tr");
	  itemsByRow = 1;
	}
    }
  
  content += closeTag("tr");
  
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

/// Replace existing items
void
WebTable::setItems(const QStringList& i)
{
  items = i;
}

void
WebTable::appendItems(const QStringList& l)
{
  items.append(l);
}

void
WebTable::appendItem(const QString& i)
{
  items.append(i);
}
