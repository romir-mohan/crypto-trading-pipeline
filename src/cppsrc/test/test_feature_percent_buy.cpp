#include "gtest/gtest.h"
#include "/home/runner/work/intern-project/intern-project/src/cppsrc/features/percent_buy_feature.hpp"

TEST(FeatureTests, PctBuyTest)
{
    intproj::PercentBuyFeature ptf;
    EXPECT_EQ(ptf.compute_feature({{1, 1, false}}), 0);
    EXPECT_EQ(ptf.compute_feature({{1, 1, false}, {1, 1, true}}), 0.5);
    EXPECT_EQ(ptf.compute_feature({{1, 1, true}}), 1);
}
