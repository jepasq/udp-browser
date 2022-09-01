#ifndef __WEB_CONTENT_HPP__
#define __WEB_CONTENT_HPP__

#include <QString>
#include <list>

#include "Serializer.hpp"


class WebFile;

/** This class keeps the content of a website in disk
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
  std::list<WebFile*> files;
  
};

#endif // !__WEB_CONTENT_HPP__
