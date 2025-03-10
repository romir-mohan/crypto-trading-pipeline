#include <tuple>
#include <vector>

#include "/home/runner/work/intern-project/intern-project/src/cppsrc/features/base_feature.hpp"

#pragma once

namespace intproj {

class PercentSellFeature : public BaseFeature
{
  public:
    float compute_feature(std::vector<std::tuple<float, float, bool>> data) override
    {
        float sell_trades = 0;

        for (std::tuple<float, float, bool> &trade : data) {
            if (!std::get<2>(trade)) sell_trades++;
        }

        return (sell_trades / data.size());
    }
};


}
