#include "gtest/gtest.h"

#include "resource.h"

#include <string>

class ResourceHelper : public Resource
{
public:
    bool ParseKeywords (std::istream& stream)
    {
        return Resource::ParseKeywords(stream);
    }

    bool ParseDictionary (std::istream& stream)
    {
        return Resource::ParseDictionary(stream);
    }

};

class ResourceFixture : public ::testing::Test
{
public:
    ResourceHelper resource;

    std::string begin = "hello";
    std::string end = "end";

    std::vector <std::string> words {"word0","word1","words2"};

    std::stringstream ssKeywords;
};

TEST_F(ResourceFixture,ShouldParseDictionary)
{
    std::stringstream ssKeywords, ssDictionary;
    ssDictionary << words.at(0) << std::endl << words.at(1) << std::endl << words.at(2) << std::endl;
    resource.ParseDictionary(ssDictionary);

    EXPECT_EQ(resource.GetDictionary(),std::set <std::string>(words.begin(),words.end()));

}

TEST_F(ResourceFixture,ShouldParseBeginEnd)
{
    std::stringstream ssKeywords;
    ssKeywords << begin << std::endl << end << std::endl;
    resource.ParseKeywords(ssKeywords);

    EXPECT_EQ(resource.GetBegin(),std::string(begin));
    EXPECT_EQ(resource.GetEnd(),std::string(end));

}
