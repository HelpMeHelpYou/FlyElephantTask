#include "argparser.h"

bool ArgParser::Parse(int argc, const char * const * const argv)
{
    if (argc != 3)
        return false;

    this->_dataFilename.assign(argv[1]);
    this->_dictionaryFilename.assign(argv[2]);

    return true;
}

const std::string &ArgParser::GetDataFilename()
{
    return _dataFilename;
}

const std::string &ArgParser::GetDictionaryFilename()
{
    return _dictionaryFilename;
}
