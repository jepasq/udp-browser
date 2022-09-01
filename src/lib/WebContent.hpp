#ifndef __WEB_CONTENT_HPP__
#define __WEB_CONTENT_HPP__

#include <QString>

#include "Serializer.hpp"

/** This class keeps the content of a website in disk
  *
  */
class WebContent : public Serializer
{
public:
  WebContent(const QString& filen = "default-website.dat");

  virtual void save(void);
  virtual void load(void);

};

#endif // !__WEB_CONTENT_HPP__
