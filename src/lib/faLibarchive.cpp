
#include "faLibarchive.hpp"

#include <archive_entry.h>

#include <sys/stat.h>
#include <fcntl.h>

#include <iostream>
#include <sstream>    // USES ostringstream

#include <QDebug>

/** The libarchive-based FileArchiver class constructor
  *
  */
faLibarchive::faLibarchive()
{

}

/** Write archived files to the archive named 'filename'
  *
  * Will throw a runtime_error exception if archive's filename is empty.
  *
  */
void
faLibarchive::write()
{
  if (filename.empty())
    throw std::runtime_error("Can't save an archive with empty filename");
  
  // Mainly from https://github.com/libarchive/libarchive/wiki/Examples#a-basic-write-example
  const char* outname = filename.c_str();
  struct archive *a;
  struct archive_entry *entry;
  struct stat st;
  char buff[8192];
  int len;
  int fd;

  a = archive_write_new();
  archive_write_add_filter_gzip(a);
  archive_write_set_format_pax_restricted(a); // Note 1
  archive_write_open_filename(a, outname);

  for (auto file : files)
    {
      auto filename = file->getFilename().toStdString().c_str();
      auto content  = file->getContent().toStdString().c_str();
      std::cout << "Adding file "<< filename  << " to archive '" << filename
		<< "' : " << content << std::endl;

      // Note 2:
      // This example creates a fresh archive_entry object for each file. For
      // better performance, you can reuse the same archive_entry object by
      // using `archive_entry_clear()` to erase it after each use. 
      entry = archive_entry_new(); 
      if (file->getFilename().toStdString().empty())
	std::cout << "WARNING : Added file with empty name" << std::endl;
	
      archive_entry_set_pathname(entry, filename);

      std::cout << "Adding content '"<< content  << "'" << std::endl;

      archive_entry_set_size(entry, strlen(content)); // Note 3
      archive_entry_set_filetype(entry, AE_IFREG);
      archive_entry_set_perm(entry, 0644);
      archive_write_header(a, entry);
      archive_write_data(a, content, strlen(content));
      archive_entry_free(entry);
    }
  archive_write_close(a); // Note 4
  archive_write_free(a); // Note 5
}

/** Simply print libarchive errors in srd::cerr
  *
  * \param a      The used archive.
  * \param valret The return value of the issued commabd.
  *
  */
void
faLibarchive::debugArchiveError(struct archive *a, int valret) const
{
  const char* errs = "";
  auto errn = archive_errno(a);
  if (errn != 0)
    errs = archive_error_string(a);
  
  std::cerr << "Valret = '"  << valret << "' ("
	    << faStatusToStr(valret) << ") errno=" << errn << "; " << errs
	    << std::endl;
}


/** Read and load content of archive found in filename
  *
  */
void
faLibarchive::read()
{
  // Notes from https://github.com/libarchive/libarchive/wiki/Examples#list-contents-of-archive-stored-in-file

  using std::cout;
  using std::endl;
  
  const char* outname = filename.c_str();

  struct archive *a;
  struct archive_entry *entry;
  char buff[1024];
  
  a = archive_read_new();
  archive_read_support_filter_all(a);
  archive_read_support_format_all(a);
  int r = archive_read_open_filename(a, outname, 1024); // Note 1
  if (r != ARCHIVE_OK)
    {
      std::ostringstream oss;
      oss << "Can't read archive file named '" << filename << "'";
      throw std::runtime_error(oss.str());
    }
  auto valret = archive_read_next_header(a, &entry);
  debugArchiveError(a, valret);

  while (archive_read_next_header(a, &entry) == ARCHIVE_OK)
    {
      // Here is the filename
      auto entryname = archive_entry_pathname(entry);
      cout << "About to add file '" << entryname << "'" << endl;
      auto addedfile = addFile(entryname);
      
      // result may be read bytes
      auto result = archive_read_open_memory(a, buff, sizeof(buff));
      char* pc = (char*)buff;
      std::cout << "'("  << result << ") '" << pc << "'" << std::endl;
      addedfile->setContent(pc);
  }
  archive_read_close(a);
  r = archive_read_free(a);
  if (r != ARCHIVE_OK)
    {
      std::ostringstream oss;
      oss << "Can't free memory for archive '" << filename << "'";
      throw std::runtime_error(oss.str());
    }
}

/** Return a string from a libarchive status code
  *
  * From https://nxmnpg.lemoda.net/3/archive_read_next_header
  *
  * \param status The code from a call to archive_read_next_header().
  *
  * \return A human readable string representation.
  *
  */
std::string
faLibarchive::faStatusToStr(int status) const
{
  std::string ret;
  switch (status)
    {
    case ARCHIVE_OK:    ret = "ARCHIVE_OK";     break;
    case ARCHIVE_WARN:  ret = "ARCHIVE_WARN";   break;
    case ARCHIVE_EOF:   ret = "ARCHIVE_EOF";    break;
    case ARCHIVE_RETRY: ret = "ARCHIVE_RETRY";  break;
    case ARCHIVE_FATAL: ret = "ARCHIVE_FATAL";  break;
    }
  return ret;
}

