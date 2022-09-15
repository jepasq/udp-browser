#ifndef __SERIALIZER_HPP__
#define __SERIALIZER_HPP__

#include <QString>
#include <QFile>

/** The object used to load abnd save files
  *
  */
class Serializer
{
public:
  Serializer(const QString&);

  QFile& load(/* ProjectFile* or WebContent */);
  QFile& save(/* ProjectFile* */);

  void close();
  
  const QString& getFilename(void) const;
  void           setFilename(const QString&);
  
protected:
  QString filename;  //!< The target path
  QFile file;        //!< The actual file
};

#endif // !__SERIALIZER_HPP__

