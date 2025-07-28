#include "gtest/gtest.h"
#define UNIT_TEST
void testTshirtSize();
void testPrintColorMap();
void testWeatherReport();

TEST(TShirt, Size) {
    testTshirtSize();
}

TEST(ColorMap, Print) {
    testPrintColorMap();
}

TEST(WeatherReport, Report) {
    testWeatherReport();
}
