#include "Serializer.hpp"

#include <QFile>
#include <QDataStream>

Serializer::Serializer(const QString& fname):
  filename(fname)
{
  
}

void
Serializer::save()
{
  QFile file(filename);
  file.open(QIODevice::WriteOnly);
  QDataStream out(&file);   // we will serialize the data into the file
  /*  out << QString("the answer is");   // serialize a string
  out << (qint32)42;        // serialize an integer
  */
}

void
Serializer::load()
{
  QFile file(filename);
  file.open(QIODevice::ReadOnly);
  QDataStream in(&file); 
}

const QString&
Serializer::getFilename(void) const
{
  return filename;
}

void
Serializer::setFilename(const QString& fname)
{
  filename = fname;
}
