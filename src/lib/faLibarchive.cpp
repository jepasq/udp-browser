
#include "faLibarchive.hpp"

#include <archive.h>
#include <archive_entry.h>

#include <sys/stat.h>
#include <fcntl.h>

#include <cstring>
#include <iostream>

#include <QDebug>

faLibarchive::faLibarchive()
{

}

/** Write archived files to the filename archive
  *
  */
void
faLibarchive::write()
{
  // Mainly from https://github.com/libarchive/libarchive/wiki/Examples#a-basic-write-example

  const char* outname = filename.c_str();
  struct archive *a;
  struct archive_entry *entry;
  struct stat st;
  char buff[8192];
  int len;
  int fd;

  
  a = archive_write_new();
  //  archive_write_add_filter_gzip(a);
  archive_write_set_format_pax_restricted(a); // Note 1
  archive_write_open_filename(a, outname);

  for (auto file : files)
    {

      auto filename = file->getFilename().toStdString().c_str();
      auto content  = file->getContent().toStdString().c_str();
      std::cout << filename  << ": " << content << std::endl;
      
      entry = archive_entry_new(); // Note 2
      archive_entry_set_pathname(entry, "aze");
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

/** Load content of archive found in filename
  *
  */
void
faLibarchive::load()
{
  // Notes from https://github.com/libarchive/libarchive/wiki/Examples#list-contents-of-archive-stored-in-file

  const char* outname = filename.c_str();

  struct archive *a;
  struct archive_entry *entry;
  char buff[1024];
  
  a = archive_read_new();
  archive_read_support_filter_all(a);
  archive_read_support_format_all(a);
  int r = archive_read_open_filename(a, outname, 1024); // Note 1
  if (r != ARCHIVE_OK)
    exit(1);
  while (archive_read_next_header(a, &entry) == ARCHIVE_OK)
    {
      // Here if the filename
      //  files.push_back(archive_entry_pathname(entry)); 
      auto addedfile = addFile(archive_entry_pathname(entry));
      // result may be read bytes
      auto result = archive_read_open_memory(a, buff, sizeof(buff));
      char* pc = (char*)buff;
      std::cout << "'("  << result << ") '" << pc << "'" << std::endl;
      addedfile->setContent(pc);

    
    archive_read_data_skip(a);  // Note 2
  }
  r = archive_read_free(a);  // Note 3
  if (r != ARCHIVE_OK)
    exit(1);
}
