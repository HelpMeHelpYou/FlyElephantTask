#ifndef FLYTOELEPHANTALGORYTHM_H
#define FLYTOELEPHANTALGORYTHM_H

#include <vector>
#include <set>
#include <string>

class FlyToElephantAlgorythm
{
public:
    FlyToElephantAlgorythm() =default;

    std::vector<std::string>  doWork(std::string beginWord, std::string endWord, std::set<std::string> dictionary);

private:
    bool IsDistanceReplacing1Letter (const std::string &s1, const std::string &s2);
};

#endif // FLYTOELEPHANTALGORYTHM_H
