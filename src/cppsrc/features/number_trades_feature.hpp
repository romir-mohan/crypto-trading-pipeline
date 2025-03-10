#include <tuple>
#include <vector>

#include "/home/runner/work/intern-project/intern-project/src/cppsrc/features/base_feature.hpp"

#pragma once

namespace intproj {

class NumberTradesFeature : public BaseFeature
{
  public:
    float compute_feature(std::vector<std::tuple<float, float, bool>> data) override
    {
        return data.size();
    }
};

}
