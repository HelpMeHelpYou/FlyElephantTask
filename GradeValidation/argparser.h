#ifndef ARGPARSER_H
#define ARGPARSER_H

#include <string>

class ArgParser
{
public:
    ArgParser() = default;
    bool Parse(int agrc, const char * const * const argv);

    const std::string& GetDataFilename ();
    const std::string& GetDictionaryFilename ();

private:
    ArgParser(ArgParser&) = delete;

    std::string _dataFilename;
    std::string _dictionaryFilename;

};
#endif // ARGPARSER_H
