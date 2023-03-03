#define BOOST_TEST_DYN_LINK
#define BOOST_TEST_MODULE Test

#include <boost/test/unit_test.hpp>
#include "compute.hpp"

BOOST_AUTO_TEST_CASE(return_callsign){
    std::string sample_string = "1672667457,2023-01-02T13:50:57Z,HAL89,\"42.371895,-71.02198\",0,4,45";
    //std::cout << "This is the string: " << sample_string << std::endl;
	BOOST_CHECK_EQUAL(get_callsign(sample_string), "HAL89");

}