#include "engine/objects/gameObject.hpp"
#include <gtest/gtest.h>

TEST(GAMEOBJECT, AddChildrenShouldTransformChildrenPositionRelativeToParent)
{
    GameObject parent(1, 1);
    GameObject children(2, 2);

    parent.addChildren(&children);

    GTEST_ASSERT_EQ(children.getPosition().x, 3);
    GTEST_ASSERT_EQ(children.getPosition().y, 3);
}

TEST(GAMEOBJECT, shouldFail)
{
    GTEST_ASSERT_EQ(true, false);
}

int test(int argc, char *argv[])
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}