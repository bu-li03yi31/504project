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
            return left.second <= right.second;
            //return left.first.compare(right.first) == 0 && left.second < right.second;
            /*if(left.first.compare(right.first) == 0){
                return false;
            }else{
                return left.second <= right.second;
            }*/
        }
    };
    set<pair<string, int>, myComparator> queue;

    queue.insert(make_pair("zord", 5));
    queue.insert(make_pair("lord", 4));
    queue.insert(make_pair("cord", 49));
    queue.insert(make_pair("dord", 40));
    queue.insert(make_pair("pord", 46));
    queue.insert(make_pair("word", 414));
    //queue.insert(make_pair("cord", 50));



    cout << queue.begin() -> first << endl;
    queue.erase(queue.begin());
    cout << queue.begin() -> first << endl;
    cout << queue.size() << endl;

    return 0;
}