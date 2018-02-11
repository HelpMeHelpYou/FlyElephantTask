#include <iostream>
#include <vector>
#include <string>

#include "errno.h"

#include "argparser.h"
#include "resource.h"
#include "flytoelephantalgorythm.h"

int main(int argc, char ** argv)
{
    ArgParser argparser;
    if(!argparser.Parse(argc,argv))
        return -EINVAL;

    Resource resource;
    resource.LoadData(argparser.GetDataFilename(),argparser.GetDictionaryFilename());

    FlyToElephantAlgorythm algo;
    std::vector<std::string> result = algo.doWork(resource.GetBegin(),resource.GetEnd(),resource.GetDictionary());

    for (std::string str : result )
    {
        std::cout << str << std::endl;
    }

    return 0;
}
