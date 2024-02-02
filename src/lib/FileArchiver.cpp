#include "FileArchiver.hpp"

#include "WebFile.hpp"

#include <iostream>

/** Default constructor
  *
  */
FileArchiver::FileArchiver()
{

}

/** Add a new empty file with the given name
  *
  * This will add a shared ptr to the given file to the local
  * files member.
  *
  * \param file The file name.
  *
  * \return The created shared_ptr to the added file.
  *
  */
std::shared_ptr<WebFile>
FileArchiver::addFile(const std::string& file)
{
  auto sp = std::make_shared<WebFile>();
  files.push_back(std::move(sp));
  std::cout << "II Adding file '" << file << "'. File list len is now "
	    << files.size() << std::endl;
  
  return sp;
}

/** Returns the current file list
  *
  * \return The files as a custom type.
  *
  */
tFileList
FileArchiver::getFiles(void) const
{
  return files;
}

/** Set the archive filename without any test
  *
  * \param str The new filename.
  *
  */
void
FileArchiver::setFilename(const std::string& str)
{
  filename = str;
}

/** Return the actual filename
  *
  * \return The archive file name as a string.
  *
  */
const std::string&
FileArchiver::getFilename(void) const
{
  return filename;
}
