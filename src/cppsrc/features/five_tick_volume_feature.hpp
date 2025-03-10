#include <numeric>
#include <tuple>
#include <vector>

#include "/home/runner/work/intern-project/intern-project/src/cppsrc/features/base_feature.hpp"

#pragma once

namespace intproj {

class FiveTickVolumeFeature : public BaseFeature
{
  private:
    float Volumes[5] = { 0, 0, 0, 0, 0 };
    int tick = 0;

  public:
    float compute_feature(std::vector<std::tuple<float, float, bool>> data) override
    {
        Volumes[tick] = 0;

        for (const auto& trade : data) 
        {
            Volumes[tick] += std::get<1>(trade);
        }

        tick = (tick + 1) % 5;

        return std::accumulate(std::begin(Volumes), std::end(Volumes), 0.0, std::plus<float>());
    }
};


}
