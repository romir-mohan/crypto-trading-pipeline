#include <iostream>
#include <tuple>
#include <vector>

#include "/home/runner/work/intern-project/intern-project/src/cppsrc/features/base_feature.hpp"

#pragma once

namespace intproj {

class PercentBuyFeature : public BaseFeature
{
  public:
    float compute_feature(std::vector<std::tuple<float, float, bool>> data) override
    {
        float buy_trades = 0;

        for (std::tuple<float, float, bool> &trade : data) {
            if (std::get<2>(trade)) buy_trades++;
        }

        return (buy_trades / data.size());
    }
};


}
