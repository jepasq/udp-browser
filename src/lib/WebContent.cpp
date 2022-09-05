#include "WebContent.hpp"

#include <QFile>
#include <QDataStream>

#include <cstddef>   //!< USES std::size_t

#include "WebFile.hpp"

WebContent::WebContent(const QString& filen):
  Serializer(filen)
{
}

void
WebContent::save(void)
{
  QDataStream ds(&Serializer::save());
  int st = files.size();
  ds << st;
  
  for (auto f : files)
    f->save(ds);
  
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

  int st;
  ds >> st;

  for (int i=0; i<st; ++i)
    {
      auto wf = new WebFile();
      wf->load(ds);
      files.push_back(wf);
    }
  
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

