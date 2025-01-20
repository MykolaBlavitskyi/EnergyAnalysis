#include <gtest/gtest.h>
#include "Drzewo.h"
#include "Punkt.h"

TEST(DrzewoTest, TestSumaAutokonsumpcji) {
    Drzewo drzewo;
    Punkt punkt("2021-10-03 10:15", 150.0, 100.0, 50.0, 80.0, 200.0);
    drzewo.dodajPunkt(punkt);
    ASSERT_EQ(drzewo.sumaAutokonsumpcji(2021, 10, 3, 2), 150.0);
}