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

  void load(QDataStream&);
  void save(QDataStream&);

  const QString& getContent(void) const;
private:
  QString content;
};

#endif // !__WEB_FILE_HPP__

