#include "engine/math/point.hpp"
#include "engine/math/geometryHelpers.hpp"
#include <gtest/gtest.h>

TEST(GEOMETRYHELPERS, ShouldReturnTrueIfPointIsInsideTriangle)
{
    GTEST_ASSERT_EQ(true, GEOMETRY_HELPERS::isPointInTriangle(Point(1, 1), Point(0, 0), Point(1, 1), Point(0, 1)));
}

int test(int argc, char *argv[])
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}