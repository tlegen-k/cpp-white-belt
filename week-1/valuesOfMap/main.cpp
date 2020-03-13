#include <string>
#include <vector>
#include <map>
#include <set>
#include <iostream>
using namespace std;

set<string> BuildMapValuesSet(const map<int, string>& m)
{
    set<string> values;
    for (auto item : m)
    {
    values.insert(item.second);
    }
    return values;
}


