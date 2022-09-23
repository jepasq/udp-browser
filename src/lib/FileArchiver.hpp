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

  void               setOutput(const std::string&);
  const std::string& getOutput(void) const;

  /** Process the input files into a single output file */
  virtual void process()=0;
  
protected:
  tFileList files;
  std::string output;
};

#endif // !__FILE_ARCHIVER_HPP__

