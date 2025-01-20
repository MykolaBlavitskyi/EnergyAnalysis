#include <gtest/gtest.h>
#include "Punkt.h"

TEST(PunktTest, TestValues) {
    Punkt punkt("2021-10-03 10:15", 150.0, 100.0, 50.0, 80.0, 200.0);
    ASSERT_EQ(punkt.getAutokonsumpcja(), 150.0);
    ASSERT_EQ(punkt.getEksport(), 100.0);
}