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
void
FileArchiver::addFile(const std::string& file)
{
  files.push_back(std::make_shared<WebFile>());
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
