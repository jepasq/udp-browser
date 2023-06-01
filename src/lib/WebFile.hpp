#ifndef __WEB_FILE_HPP__
#define __WEB_FILE_HPP__

#include <QDataStream>

/** Defines a file that is added to WebContent
  *
  */
class WebFile
{
public:
  WebFile();
  WebFile(const QString&);

  void load(QDataStream&);
  void save(QDataStream&);

  const QString& getContent(void) const;
  void           setContent(const QString&);

  const QString& getFilename(void) const;
  void           setFilename(const QString&);
  
private:
  QString filename;  //!< The file name
  QString content;   //!< The file content
};

#endif // !__WEB_FILE_HPP__

