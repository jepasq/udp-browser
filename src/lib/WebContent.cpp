#include "WebContent.hpp"

#include <QFile>
#include <QDataStream>
#include <iostream>

#include "FileArchiver.hpp"
#include "FileCompressor.hpp"
#include "WebFile.hpp"

/** Current written version */
constexpr int CURRENT_VERSION = 2;

WebContent::WebContent(const QString& filen, const QString& vname):
  version(CURRENT_VERSION),
  Serializer(filen),
  name(vname),
  fa(nullptr),
  fc(nullptr)
{
  
}

void
WebContent::save(void)
{
  QDataStream ds(&Serializer::save());

  ds << version;

  ds << name;
  
  int st = files.size();
  ds << st;
  
  for (auto f : files)
    f->save(ds);
  
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


  ds >> name;
  
  int st;
  ds >> st;

  for (int i=0; i<st; ++i)
    {
      auto wf = std::make_shared<WebFile>();
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
  std::shared_ptr<WebFile> ff(wf);
  files.push_back(ff);
}


void
WebContent::setName(const QString& vname)
{
  name = vname;
}

const QString&
WebContent::getName(void) const
{
  return name;
}
