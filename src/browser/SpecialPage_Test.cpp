#include "SpecialPage.hpp"

#include <boost/test/unit_test.hpp>

#include <stdexcept> // USES std::runtime_error

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

