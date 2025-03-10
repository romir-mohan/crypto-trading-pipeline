#include "gtest/gtest.h"
#include "/home/runner/work/intern-project/intern-project/src/cppsrc/features/five_tick_volume_feature.hpp"

TEST(FeatureTests, TestFiveTickVolume)
{
    intproj::FiveTickVolumeFeature vf;
    EXPECT_EQ(vf.compute_feature({ { 2, 1, false } }), 1);
    EXPECT_EQ(vf.compute_feature({ { 1, 1, false } }), 2);
    EXPECT_EQ(vf.compute_feature({ { 1, 1, false }, { 1, 1, true } }), 4);
    EXPECT_EQ(vf.compute_feature({ { 1, 1, false }, { 1, 1, true } }), 6);
    EXPECT_EQ(vf.compute_feature({ { 2, 1, false }, { 1, 1, true } }), 8);
    EXPECT_EQ(vf.compute_feature({ { 1, 1, false }, { 1, 1, true } }), 9);
    EXPECT_EQ(vf.compute_feature({ { 2, 1, false }, { 1, 1, true } }), 10);
}
