#include "WebTable.hpp"

#include <iostream>

/** Constructor with standard quote
  *
  */
WebTable::WebTable(): QUOTE('\'')
{

}

/** Return the HTML representation of the current table
  *
  * Will be used with SpecialPage::replaceText as QString
  *
  * @return The current table content as HTML table string.
  *
  */
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

/** Set the headers list replacing the current one
  *
  * \param sl The new list.
  *
  */
void
WebTable::setHeaders(const QStringList& sl)
{
  headers = sl;
}

/** Create and return an open HTML tag with optional class
  *
  * The class uses the current QUOTE character.
  *
  * \param tag       The markup tag.
  * \param className The class(es) tp be applied.
  *
  * \return The opening tag with quoted class.
  *
  */
QString
WebTable::openTag(const QString& tag, const QString& className)
{
  if (className.isEmpty())
    return QString("<" + tag + ">");

  return QString("<" + tag + " class=" + QUOTE + className + QUOTE + ">");
}

/** Return a closing HTML tag
  *
  */
QString 
WebTable::closeTag(const QString& tag)
{
  return QString("</" + tag + ">");
}

/** Replace the current quote char set in constructor
  *
  * \param c The new char.
  *
  */
void
WebTable::changeQuoteChar(char c)
{
  QUOTE = c;
}

/** Replace all existing items
 *
 * \param i The enw item list.
 *
 */
void
WebTable::setItems(const QStringList& i)
{
  items = i;
}

/** Append multiple items at once
  *
  * \param l The list of element to be added.
  *
  */
void
WebTable::appendItems(const QStringList& l)
{
  items.append(l);
}

/** Append the given text item
  *
  * \param i The item to be added.
  *
  */
void
WebTable::appendItem(const QString& i)
{
  items.append(i);
}

void
WebTable::appendItem(const std::string& str)
{
  appendItem(QString(str.c_str()));
}

void
WebTable::appendItem(const char* str)
{
  appendItem(QString(str));
}
