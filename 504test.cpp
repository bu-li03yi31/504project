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
    const bool is_in = queue.find(make_pair("lord", 3)) != queue.end();
    cout << is_in << endl;
    queue.erase(queue.begin());
    cout << queue.begin() -> first << endl;
    return 0;
}