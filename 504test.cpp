#include <iostream>
#include <string>
#include <set>
using namespace std;

int main ()
{
    struct myComparator
    {
        bool operator() (const std::pair<string, int>& left, const std::pair<string, int>& right) const
        {
            return left.second < right.second;
        }
    };
    set<pair<string, int>, myComparator> queue;

    queue.insert(make_pair("word", 5));
    queue.insert(make_pair("lord", 4));

    cout << queue.begin() -> first << endl;
    pair<string, int> tmp = make_pair("lord", 4);
    const bool is_in = queue.find(tmp) != queue.end();
    cout << is_in << endl;
    queue.erase(tmp);
    const bool is_in2 = queue.find(tmp) != queue.end();
    cout << is_in2 << endl;
    cout << queue.begin() -> first << endl;
    return 0;
}