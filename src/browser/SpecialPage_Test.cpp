#include "SpecialPage.hpp"

#include <boost/test/unit_test.hpp>

#include <stdexcept> // USES std::runtime_error

/// To be able to test protected functions
class TestableSpecialPage : public SpecialPage
{
public:
  /** Used to test a protected function
    *
    * @param a The text to be replaced.
    * @param b The test that will replace 'a'.
    *
    * @return The modified text.
    *
    */
  QString _replaceText(const QString& a, const QString& b){
    return replaceText(a,b);
  }
};


BOOST_AUTO_TEST_CASE( SpecialPage_hasNameAttribute )
{
  SpecialPage sp;
  sp.setName("AZE");
  BOOST_CHECK( sp.getName() == "AZE" );
}

BOOST_AUTO_TEST_CASE( SpecialPage_hasCommentAttribute )
{
  SpecialPage sp;
  sp.setComment("CoMMent");
  BOOST_CHECK( sp.getComment() == "CoMMent" );
}

/// Check that trying to replace an inexisting to be replaced text
/// throws an exception
BOOST_AUTO_TEST_CASE( SpecialPage_InvalidTobeReplacedText )
{
  TestableSpecialPage sp;
  sp.setMediaContent("about");
  QString INEXIST = "A_VERY_INCONSISTENT_TOBEREPLACED_TEXT";
  BOOST_CHECK_THROW(sp._replaceText(INEXIST, "aze"), std::runtime_error);

  // Note, depends on 'media/index.html' content
  BOOST_CHECK_NO_THROW(sp._replaceText("{{SPAGES}}", "aze"));
}

