#include "FileArchiver.hpp"

#include "WebFile.hpp"

FileArchiver::FileArchiver()
{

}

/** Add a new empty file with the given name
  *
  * \param file The file name.
  *
  */
std::shared_ptr<WebFile>
FileArchiver::addFile(const std::string& file)
{
  auto sp = std::make_shared<WebFile>();
  files.push_back(sp);
  return sp;
}

tFileList
FileArchiver::getFiles(void) const
{
  return files;
}

void
FileArchiver::setFilename(const std::string& str)
{
  filename = str;
}

const std::string&
FileArchiver::getFilename(void) const
{
  return filename;
}
