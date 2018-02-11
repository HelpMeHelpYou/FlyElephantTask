#include "argparser.h"

#include "gtest/gtest.h"

#include "string.h"

class TestArgParserFixture : public ::testing::Test
{
public:
    std::string param0 = "program";
    std::string  param1 ="arg0";
    std::string  param2 ="arg1";
    const char*  args [3] = {param0.c_str(),param1.c_str(),param2.c_str()};

    ArgParser argParser;
};

TEST_F(TestArgParserFixture,ShouldParse3args)
{
    EXPECT_EQ(argParser.Parse(3,args),true);
    EXPECT_EQ(argParser.GetDataFilename(),param1);
    EXPECT_EQ(argParser.GetDictionaryFilename(),param2);
}

TEST_F(TestArgParserFixture,ShouldNotParse2args)
{
    EXPECT_EQ(argParser.Parse(2,args),false);
}
