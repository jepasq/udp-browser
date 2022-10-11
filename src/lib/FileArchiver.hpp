#ifndef __FILE_ARCHIVER_HPP__
#define __FILE_ARCHIVER_HPP__

#include <string>
#include <vector>

typedef std::vector<std::string> tFileList;

/** An archiver abstract class for both read and write web content files
  *
  */
class FileArchiver {
public:
  FileArchiver();
  
  void addFile(const std::string&);

  tFileList getFiles(void) const;

  void               setFilename(const std::string&);
  const std::string& getFilename(void) const;

  /** Process the input files into a single output file */
  virtual void write()=0;
  /** Load the file */
  virtual void load()=0;
  
protected:
  tFileList files;      //!< The files to be added to the archive
  std::string filename; // Archive filename
};

#endif // !__FILE_ARCHIVER_HPP__

