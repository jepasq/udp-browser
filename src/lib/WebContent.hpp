#ifndef __WEB_CONTENT_HPP__
#define __WEB_CONTENT_HPP__

#include <QString>
#include <list>

#include "Serializer.hpp"


class WebFile;

/** This class keeps the content of a website in disk
  *
  * The versionning scheme is very simple for instance and for each
  * modification done to the WebFile or WebContent serialization process
  * (order, field etc...) we must increment the CURRENT_VERSION constexpr
  * found in WebContent.cpp file.
  *
  */
class WebContent : public Serializer
{
public:
  WebContent(const QString& filen = "default-website.dat");

  virtual void save(void);
  virtual void load(void);

  int getFileNumber(void) const;
  void addFile(WebFile*);

private:
  int version;                 //!w The version to be serialized
  std::list<WebFile*> files;   //!< Current list of files
  
};

#endif // !__WEB_CONTENT_HPP__
