#include <tuple>
#include <vector>

#pragma once

namespace intproj {

class BaseFeature
{
  public:
    virtual float compute_feature(std::vector<std::tuple<float, float, bool>> data) = 0;

    virtual ~BaseFeature() {}
};


}// namespace intproj
