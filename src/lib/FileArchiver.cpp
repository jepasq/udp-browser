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
FileArchiver::setOutput(const std::string& str)
{
  output = str;
}

const std::string&
FileArchiver::getOutput(void) const
{
  return output;
}
