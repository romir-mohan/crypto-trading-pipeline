#include "gtest/gtest.h"
#include "../number_trades_feature.hpp"

TEST(FeatureTests, NTradesTest)
{
    intproj::NTradesFeature ntf;
    EXPECT_EQ(ntf.compute_feature({{1, 1, false}}), 1);
    EXPECT_EQ(ntf.compute_feature({{2, 1, false}, {2, 2, true}}), 2);
}
