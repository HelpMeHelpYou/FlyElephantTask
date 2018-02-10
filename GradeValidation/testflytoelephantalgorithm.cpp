#include "flytoelephantalgorythm.h"
#include <vector>
#include <string>
#include "gtest/gtest.h"

TEST(flytoelephantalgorythm,ShoudlWorkCommonTest)
{
    std::set<std::string> dict = { "КОТ", "ТОН", "НОТА", "КОТЫ", "РОТ", "РОТА", "ТОТ"};
    std::string begin ="КОТ";
    std::string end ="ТОН";

    std::vector<std::string> answer = {"КОТ", "ТОТ", "ТОН" };

    FlyToElephantAlgorythm algo;

    std::vector<std::string> result = algo.doWork(begin,end,dict);
    EXPECT_EQ(result,answer);
}

TEST(flytoelephantalgorythm,ShoudlWorkTheSameKeyTest)
{
    std::set<std::string> dict = { "dog", "wolf" };
    std::string begin ="cat";
    std::string end ="cat";

    std::vector<std::string> answer = {"cat"};

    FlyToElephantAlgorythm algo;

    std::vector<std::string> result = algo.doWork(begin,end,dict);
    EXPECT_EQ(result,answer);
}

TEST(flytoelephantalgorythm,ShoudlWorkTheSameKeyTest2)
{
    std::set<std::string> dict = { "dog", "wolf","cat" };
    std::string begin ="cat";
    std::string end ="cat";

    std::vector<std::string> answer = {"cat"};

    FlyToElephantAlgorythm algo;

    std::vector<std::string> result = algo.doWork(begin,end,dict);
    EXPECT_EQ(result,answer);
}


TEST(flytoelephantalgorythm,ShoudlWorkNoSolutionTest2)
{
    std::set<std::string> dict = { "dog", "wolf" };
    std::string begin ="cat";
    std::string end ="tiger";

    std::vector<std::string> answer = {};

    FlyToElephantAlgorythm algo;

    std::vector<std::string> result = algo.doWork(begin,end,dict);
    EXPECT_EQ(result,answer);
}
