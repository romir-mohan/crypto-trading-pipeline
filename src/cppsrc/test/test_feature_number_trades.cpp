#include "gtest/gtest.h"
#include "/home/runner/work/intern-project/intern-project/src/cppsrc/features/number_trades_feature.hpp"

TEST(FeatureTests, NTradesTest)
{
    intproj::NumberTradesFeature ntf;
    EXPECT_EQ(ntf.compute_feature({{1, 1, false}}), 1);
    EXPECT_EQ(ntf.compute_feature({{2, 1, false}, {2, 2, true}}), 2);
}
