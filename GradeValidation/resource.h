#ifndef RESOURCE_H
#define RESOURCE_H

#include <istream>
#include <set>

class Resource
{
public:
    Resource() = default;
    const std::string& GetBegin();
    const std::string& GetEnd();
    const std::set <std::string>& GetDictionary();

    bool LoadData (std::string keywordFilePath, std::string dicitionaryFilePath);

protected:
    bool ParseKeywords (std::istream &stream);
    bool ParseDictionary (std::istream &stream);

private:
    std::string _begin;
    std::string _end;
    std::set <std::string> _dictionary;
};

#endif // RESOURCE_H
