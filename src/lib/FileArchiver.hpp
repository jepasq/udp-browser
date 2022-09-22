#ifndef __FILE_ARCHIVER_HPP__
#define __FILE_ARCHIVER_HPP__

#include <string>
#include <vector>

typedef std::vector<std::string> tFileList;

class FileArchiver {
public:
  FileArchiver();
  
  void addFile(const std::string&);

  tFileList getFiles(void) const;
  
private:
  tFileList files;
};

#endif // !__FILE_ARCHIVER_HPP__

