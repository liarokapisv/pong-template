#include <gtest/gtest.h>
//#include <rapidcheck/gmock.h>

auto main(int argc, char * argv[]) -> int
{
    testing::InitGoogleTest(&argc, argv);
    //rc::gmock::RapidCheckListener::install();
    return RUN_ALL_TESTS();
}

