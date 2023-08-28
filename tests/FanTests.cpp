
#include "Fan.hpp"
#include <gtest/gtest.h>
#include <gmock/gmock.h>

using namespace std;
using namespace ::testing;

class FanTest  : public ::testing::Test{
    public:
    Fan fan{};

};
    auto disabledRpm = 0;
    auto minRpm = 1000;
    auto maxRpm = 3000;

TEST_F(FanTest, CreatedFanIsDisabled){


    ASSERT_EQ(fan.getSpeed(), disabledRpm);

}

TEST_F(FanTest, SettingPropperValues){

    fan.setSpeed(minRpm);
    ASSERT_EQ(fan.getSpeed(), minRpm);

    fan.setSpeed(maxRpm);
    ASSERT_EQ(fan.getSpeed(), maxRpm);

    fan.setSpeed(disabledRpm);
    ASSERT_EQ(fan.getSpeed(), disabledRpm);
    

}

TEST_F(FanTest, SettingInvalidValues){

    auto before = fan.getSpeed();
  
    EXPECT_THROW(fan.setSpeed(minRpm - 1),std::invalid_argument);
    ASSERT_EQ(fan.getSpeed(), before);
    
    EXPECT_THROW(fan.setSpeed(maxRpm + 1),std::invalid_argument);
    ASSERT_EQ(fan.getSpeed(), before);

}

// TEST_CASE("Fan - setSpeed() behavior", "[Fan]") {

//     Fan f{};
  

//     SECTION("created fan is disabled") {
//         CHECK(f.getSpeed() == disabledRpm);
//     }
    
//     SECTION("setting proper values") {
//         f.setSpeed(minRpm);
//         CHECK(f.getSpeed() == minRpm);

//         f.setSpeed(maxRpm);
//         CHECK(f.getSpeed() == maxRpm);

//         f.setSpeed(disabledRpm);
//         CHECK(f.getSpeed() == disabledRpm);
//     }

//     SECTION("setting invalid values") {
//         auto before = f.getSpeed();
        
//         REQUIRE_THROWS_AS(f.setSpeed(minRpm - 1), std::invalid_argument);
//         CHECK(f.getSpeed() == before);

//         REQUIRE_THROWS_AS(f.setSpeed(maxRpm + 1), std::invalid_argument);
//         CHECK(f.getSpeed() == before);
//     }
// }