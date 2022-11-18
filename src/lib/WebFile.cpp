#include "WebFile.hpp"

const QString DEFAULT_FILEANME = "aze.zer";

#include <stdexcept> // USES std::runtime_error

/** Webfile constructor
  *
  */
WebFile::WebFile():
  filename(DEFAULT_FILEANME),
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


/** Get the filename of the file
  *
  * May be an empty string.
  *
  * \return The filename of the file as a Qt string.
  *
  */
const QString&
WebFile::getFilename(void) const
{
  return filename;
}

/** Change the filename of the file
  *
  * \param c The new filename. Can be an empty string.
  *
  */
void
WebFile::setFilename(const QString& c)
{
  if (c.isEmpty())
    throw std::runtime_error("Can't set an empty WebFile filename.");
  else
    this->filename = c;
}


