#include "WebTable.hpp"

WebTable::WebTable(): QUOTE('\'')
{

}

/// Will be used with SpecialPage::replaceText as QString
QString
WebTable::toHtml()
{
  return "";
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

