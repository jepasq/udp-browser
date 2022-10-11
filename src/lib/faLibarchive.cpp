
#include "faLibarchive.hpp"

#include <archive.h>
#include <archive_entry.h>

#include <sys/stat.h>
#include <fcntl.h>

#include <cstring>

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

void
faLibarchive::load()
{

}
