#define BOOST_TEST_DYN_LINK
#define BOOST_TEST_MODULE Test

#include <boost/test/unit_test.hpp>
#include "compute.hpp"

BOOST_AUTO_TEST_CASE(get_callsign_check){
    std::string sample_string = "1672667457,2023-01-02T13:50:57Z,HAL89,\"42.371895,-71.02198\",0,4,45";
	BOOST_CHECK_EQUAL(get_callsign(sample_string), "HAL89");
}

BOOST_AUTO_TEST_CASE(get_time_stamp_check){
    std::string sample_string = "1672667457,2023-01-02T13:50:57Z,HAL89,\"42.371895,-71.02198\",0,4,45";
	BOOST_CHECK_EQUAL(get_time_stamp(sample_string), 1672667457);
}

BOOST_AUTO_TEST_CASE(get_date_check){
    std::string sample_string = "1672667457,2023-01-02T13:50:57Z,HAL89,\"42.371895,-71.02198\",0,4,45";
	BOOST_CHECK_EQUAL(get_date(sample_string), "2023-01-02");
}

BOOST_AUTO_TEST_CASE(get_latitude_check){
    std::string sample_string = "1672667457,2023-01-02T13:50:57Z,HAL89,\"42.371895,-71.02198\",0,4,45";
	BOOST_CHECK_EQUAL(get_latitude(sample_string), 42.371895);
}

BOOST_AUTO_TEST_CASE(get_longitude_check){
    std::string sample_string = "1672667457,2023-01-02T13:50:57Z,HAL89,\"42.371895,-71.02198\",0,4,45";
	BOOST_CHECK_EQUAL(get_longitude(sample_string), -71.02198);
}
