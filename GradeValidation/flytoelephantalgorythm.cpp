#include "flytoelephantalgorythm.h"

#include <vector>
#include <string>
#include <set>
#include <algorithm>
#include <iterator>
#include <queue>
#include <map>
#include <locale>
#include <utility>
#include <codecvt>
#include <deque>
struct Node;

struct Node
{
    std::map<std::string,bool>::iterator it;
    std::set<Node*> list;
    Node * parent;
    Node() : Node (NULL){}
    Node (Node * parent) : parent(parent),it(NULL){}
    ~Node()
    {
        for (Node * node :list)
        {
            delete node;
        }
    }
};

std::vector<std::string> FlyToElephantAlgorythm::doWork(std::string beginWord,
                                                          std::string endWord,
                                                          std::set<std::string> dictionary)
{
    std::deque<std::string> result;

    if (beginWord == endWord)
        return std::move(std::vector<std::string>{beginWord});

    std::map <std::string, bool> temp;
    for (std::string word : dictionary)
    {
        temp.insert(std::pair<std::string,bool>(word,false));
    }

    Node * rootNode = new Node;
    Node * currentNode = rootNode;

    std::queue <Node*> queue;

    queue.push(rootNode);

    while(!queue.empty())
    {
        currentNode = queue.front();
        queue.pop();

        for (auto it = temp.begin(); it != temp.end(); it++)
        {
            if (it->second != true)
            {

                if (IsDistanceReplacing1Letter(it->first,currentNode->it != (std::map<std::string,bool>::iterator)nullptr ? currentNode->it->first :beginWord))
                {
                    it->second = true;
                    Node * child = new Node(currentNode);
                    child->it = it;
                    currentNode->list.insert(child);
                    if (it->first == endWord)
                    {
                        currentNode = child;
                        goto out;
                    }
                    queue.push(child);

                }
            }
        }
    }
    out:
    while (currentNode->parent)
    {
        result.push_front(currentNode->it->first);
        currentNode= currentNode->parent;
    }
    if (!result.empty())
        result.push_front(beginWord);
    return std::move(std::vector<std::string>(result.begin(),result.end()));
}

bool FlyToElephantAlgorythm::IsDistanceReplacing1Letter(const std::string& s1, const std::string& s2)
{
    unsigned int count=0;

    using convert_type = std::codecvt_utf8<wchar_t>;
    std::wstring_convert<convert_type, wchar_t> converter;

    std::wstring w1 = converter.from_bytes(s1.c_str());
    std::wstring w2 = converter.from_bytes(s2.c_str());

    unsigned int minLength = std::min (w1.length(), w2.length());
    for (unsigned int i = 0; i < minLength; i++ )
    {
        if (w1.at(i) != w2.at(i))
            count++;
    }
    return count==1;
}
