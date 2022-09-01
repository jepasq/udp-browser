#include "WebContent.hpp"

#include <QFile>
#include <QDataStream>

WebContent::WebContent(const QString& filen):
  Serializer(filen)
{
}

void
WebContent::save(void)
{
  QDataStream ds(&Serializer::save());
  /*  ds << username;
  ds << quotaNum;
  ds << quotaUnit;
  */
  Serializer::close();
}

void
WebContent::load(void)
{
  QDataStream ds(&Serializer::load());
  /*  ds >> username;
  ds >> quotaNum;
  ds >> quotaUnit;
  */
  Serializer::close();
}

int
WebContent::getFileNumber(void) const
{
  return files.size();
}

void
WebContent::addFile(WebFile* wf)
{
  files.push_back(wf);
}

