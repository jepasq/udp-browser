#include "WebContent.hpp"

#include <QFile>
#include <QDataStream>
#include <iostream>

#include "FileArchiver.hpp"
#include "FileCompressor.hpp"
#include "WebFile.hpp"

/** Current written version */
constexpr int CURRENT_VERSION = 2;

/** Named constructor
  *
  * \param filen The content file name.
  * \param vname The name.
  *
  */
WebContent::WebContent(const QString& filen, const QString& vname):
  version(CURRENT_VERSION),
  Serializer(filen),
  name(vname),
  fa(nullptr),
  fc(nullptr)
{
  
}

/** Save with class members to a data stream
  *
  */
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

/** Save with class members from a data stream
  *
  */
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


/** Return the number of files in this content
  *
  * \return The size of files vector.
  *
  */
int
WebContent::getFileNumber(void) const
{
  return files.size();
}

/** Add the given file to the content vector
  *
  * \param wf The file to be added.
  *
  */
void
WebContent::addFile(WebFile* wf)
{
  std::shared_ptr<WebFile> ff(wf);
  files.push_back(ff);
}


/** Set the current name
  *
  * \param vname The new name.
  *
  */
void
WebContent::setName(const QString& vname)
{
  name = vname;
}

/** Return current name
  *
  * \return The name member as a QString.
  *
  */
const QString&
WebContent::getName(void) const
{
  return name;
}
