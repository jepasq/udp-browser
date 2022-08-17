#ifndef __SERIALIZER_HPP__
#define __SERIALIZER_HPP__

#include <QString>
#include <QFile>

class Serializer
{
public:
  Serializer(const QString&);

  QFile& load(/* ProjectFile* or WebContent */);
  QFile& save(/* ProjectFile* */);

  const QString& getFilename(void) const;
  void           setFilename(const QString&);
  
protected:
  QString filename;  //!< The target path
  QFile file;
};

#endif // !__SERIALIZER_HPP__

