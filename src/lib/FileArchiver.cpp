#include "FileArchiver.hpp"

FileArchiver::FileArchiver()
{

}
  
void
FileArchiver::addFile(const std::string& file)
{
  files.push_back(file);
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
