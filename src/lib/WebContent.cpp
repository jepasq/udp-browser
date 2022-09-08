#include "WebContent.hpp"

#include <QFile>
#include <QDataStream>
#include <iostream>

#include "WebFile.hpp"

/** Current written version */
constexpr int CURRENT_VERSION = 1;

WebContent::WebContent(const QString& filen):
  version(CURRENT_VERSION),
  Serializer(filen)
{
}

void
WebContent::save(void)
{
  QDataStream ds(&Serializer::save());

  ds << version;
  
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

  int file_version;

  ds >> file_version;
  if (file_version != version)
    std::cout << "VERSION MISMATCH " << file_version << " != " << version
	      << std::endl;
  
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

