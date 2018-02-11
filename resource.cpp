#include "resource.h"
#include <set>
#include <string>
#include <iostream>
#include <fstream>

const std::string &Resource::GetBegin()
{
    return _begin;
}

const std::string &Resource::GetEnd()
{
    return _end;
}

const std::set<std::string> &Resource::GetDictionary()
{
    return _dictionary;
}

bool Resource::LoadData(std::string keywordFilePath, std::string dicitionaryFilePath)
{
    std::fstream keywordFile;
    std::fstream dictionaryFile;

    keywordFile.open(keywordFilePath, std::fstream::in);
    dictionaryFile.open(dicitionaryFilePath, std::fstream::in);

    bool rc = ParseKeywords(keywordFile) && ParseDictionary(dictionaryFile);

    keywordFile.close();
    dictionaryFile.close();
    return rc;

}

bool Resource::ParseKeywords(std::istream &stream)
{
    try
    {
        getline(stream, _begin);
        getline(stream, _end);
    }
    catch (std::exception exp)
    {
        return false;
    }
    return true;
}

bool Resource::ParseDictionary (std::istream& stream)
{
    std::string dictionary_entry;
    try
    {
        while (true)
        {
            dictionary_entry.clear();
            getline(stream, dictionary_entry);
            if (dictionary_entry.empty())
                break;
            this->_dictionary.insert(dictionary_entry);
        }
    }
    catch (std::exception exp)
    {
        return false;
    }
    return true;
}
