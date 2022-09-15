#ifndef __WEB_CONTENT_HPP__
#define __WEB_CONTENT_HPP__

#include <QString>
#include <vector>
#include <memory>

#include "Serializer.hpp"


// Forward declarations
class FileArchiver;
class FileCompressor;
class WebFile;
// End of forward declarations

/** This class keeps the content of a website in disk
  *
  * The versionning scheme is very simple for instance and for each
  * modification done to the WebFile or WebContent serialization process
  * (order, field etc...) we must increment the CURRENT_VERSION constexpr
  * found in WebContent.cpp file.
  *
  * This class is also in charge of the archive creation and compression
  * using FileArchiver and FileCompressor classes.
  *
  */
class WebContent : public Serializer
{
public:
  WebContent(const QString& filen = "default-website.dat",
	     const QString& vname = "default");

  virtual void save(void);
  virtual void load(void);

  int getFileNumber(void) const;
  void addFile(WebFile*);

  void           setName(const QString&);
  const QString& getName(void) const;
  
private:
  int version;                 //!w The version to be serialized
  std::vector<std::shared_ptr<WebFile>> files;   //!< Current list of files
  QString name;                //!< The name od this site

  FileArchiver*   fa;
  FileCompressor* fc;
  
};

#endif // !__WEB_CONTENT_HPP__
