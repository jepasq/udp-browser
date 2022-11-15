
#include "faLibarchive.hpp"

#include <archive.h>
#include <archive_entry.h>

#include <sys/stat.h>
#include <fcntl.h>

#include <cstring>

#include <iostream>

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
  const char* filenames[] = {"package.json", "doxygen.log"};
  const char** filename = &filenames[0];
  struct archive *a;
  struct archive_entry *entry;
  struct stat st;
  char buff[8192];
  int len;
  int fd;

  auto content = "file content 01";
  
  a = archive_write_new();
  //  archive_write_add_filter_gzip(a);
  archive_write_set_format_pax_restricted(a); // Note 1
  archive_write_open_filename(a, outname);
  //  while (*filename) {
  //    stat(*filename, &st);
    entry = archive_entry_new(); // Note 2
    archive_entry_set_pathname(entry, "aze");
    archive_entry_set_size(entry, strlen(content)); // Note 3
    archive_entry_set_filetype(entry, AE_IFREG);
    archive_entry_set_perm(entry, 0644);
    archive_write_header(a, entry);
    fd = open(*filename, O_RDONLY);
    len = read(fd, buff, sizeof(buff));
    //    while ( len > 0 ) {
      archive_write_data(a, content, strlen(content));
      /*        len = read(fd, buff, sizeof(buff));
		} */
    close(fd);
    archive_entry_free(entry);
    filename++;
    //  }
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
  const void *buff;
  int r;
  
  a = archive_read_new();
  archive_read_support_filter_all(a);
  archive_read_support_format_all(a);
  r = archive_read_open_filename(a, outname, 10240); // Note 1
  if (r != ARCHIVE_OK)
    exit(1);
  while (archive_read_next_header(a, &entry) == ARCHIVE_OK) {
    //  files.push_back(archive_entry_pathname(entry)); // Here if the filename
    addFile(archive_entry_pathname(entry));
    auto r = archive_read_open_memory(a, buff, sizeof(buff));
    char* pc = (char*)buff;
    std::cout << "'("  << r << ") "
	      << pc[0] 
	      << std::endl;
    archive_read_data_skip(a);  // Note 2
  }
  r = archive_read_free(a);  // Note 3
  if (r != ARCHIVE_OK)
    exit(1);
}
