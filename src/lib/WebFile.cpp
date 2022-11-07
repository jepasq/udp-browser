#include "WebFile.hpp"

/** Webfile constructor
  *
  */
WebFile::WebFile():
  content("")
{

}

/** Load the content of this file from a stream
  *
  * \param ds The stream.
  *
  */
void
WebFile::load(QDataStream& ds)
{

}

/** Save the content of this file to the given stream
  *
  * \param ds The stream.
  *
  */
void
WebFile::save(QDataStream& ds)
{

}

/** Get the content of the file
  *
  * May be an empty string.
  *
  * \return The content of the file as a Qt string.
  *
  */
const QString&
WebFile::getContent(void) const
{
  return content;
}

/** Change the content of the file
  *
  * \param c The new content. Can be an empty string.
  *
  */
void
WebFile::setContent(const QString& c)
{
  this->content = c;
}

