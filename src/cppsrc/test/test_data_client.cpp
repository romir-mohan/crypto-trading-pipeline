#include "/home/runner/work/intern-project/intern-project/src/cppsrc/data/data_client.hpp"
#include "nlohmann/json.hpp"
#include "gtest/gtest.h"

#include <string>

std::string sample_json_unit = R"([
    {
        "timestamp": 1,
        "timestampms": 1000,
        "tid": 1,
        "price": "101.1",
        "amount": "30.1",
        "exchange": "gemini",
        "type": "buy"
    },
    {
        "timestamp": 2,
        "timestampms": 2000,
        "tid": 2,
        "price": "202.2",
        "amount": "20.2",
        "exchange": "gemini",
        "type": "buy"
    },
    {
        "timestamp": 3,
        "timestampms": 3000,
        "tid": 3,
        "price": "303.3",
        "amount": "33.3",
        "exchange": "gemini",
        "type": "sell"
    }
])";

TEST(DataClientTests, ParseMessageTest)
{
    nlohmann::json j = nlohmann::json::parse(sample_json_unit);
    intproj::DataClient data_client;

    std::vector<std::tuple<float, float, bool>> parsed = data_client.parse_message(j);

    EXPECT_EQ(parsed.size(), 3);
    EXPECT_EQ(std::get<0>(parsed[0]), 101.1f);
    EXPECT_EQ(std::get<1>(parsed[0]), 30.1f);
    EXPECT_TRUE(std::get<2>(parsed[0]));
}