#include "cpr/cpr.h"
#include "nlohmann/json.hpp"
#include "signal.hpp"

#include <string>
#include <tuple>
#include <vector>

#pragma once

namespace intproj {

class DataClient
{
  private:
    Signal signal;
    const cpr::Url url = "https://api.sandbox.gemini.com/v1/trades/btcusd";

  public:
    nlohmann::json get_data()
    {
        cpr::Response r = cpr::Get(url);

        if (r.status_code == cpr::status::HTTP_OK) {
            return nlohmann::json::parse(r.text);
        } else {
            throw std::runtime_error("error querying database");
        }
    }

    std::vector<std::tuple<float, float, bool>> parse_message(const nlohmann::json &data)
    {
        std::vector<std::tuple<float, float, bool>> trades;

        for (const auto &entry : data) {
            std::string price_s = entry["price"].get<std::string>();
            std::string volume_s = entry["amount"].get<std::string>();

            float price = std::stof(price_s);
            float volume = std::stof(volume_s);

            bool side;
            std::string type = entry["type"].get<std::string>();
            if (type == "buy") {
                side = true;
            } else if (type == "sell") {
                side = false;
            }

            trades.emplace_back(price, volume, side);
        }

        return trades;
    }

    std::tuple<std::vector<float>, float> tick()
    {
        nlohmann::json data = get_data();
        std::vector<std::tuple<float, float, bool>> trades = parse_message(data);

        return signal.compute_features(trades);
    }
};

}
