#include "WebTable.hpp"

WebTable::WebTable()
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
