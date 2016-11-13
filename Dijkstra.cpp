
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <fstream>
#include <string.h>
#include <vector>
#include <map>
#include <tuple>
#include <utility>
#include <limits>
#include <unordered_set>
#include <set>
using namespace std;


int Dijkstra(map<string, vector<pair<string,int >> >& adjacencyList
        , vector<string>& wordList, string start, string stop){
    //store path sum of each node
    map<string, int> dist;
    //store parent of each node
    map<string, string> prev;
    //our priority queue here
    //overriding the comparator of pair set

    struct QComparator
    {
        bool operator() (const std::pair<string, int>& left, const std::pair<string, int>& right) const
        {
            return left.second < right.second;
        }
    };
    set<pair<string, int>, QComparator> pq;
    for(int i = 0; i < wordList.size(); i ++){
        dist[wordList[i]] = numeric_limits<int>::max();
        prev[wordList[i]] = "*";
    }
    unordered_set<string> visited;//store the visited nodes

    return 0;
    
};

int main() {
    string list;
    string node;
    string head;
    map<string, vector<pair<string,int >> > adjacencyList;
    vector<string> wordList;
    pair< string, int> wordWeight;

    ifstream myfile ("/Users/yil/Desktop/504-project-repo/504project/4-words4_graph.txt");
    if(myfile)
    {
        while (getline(myfile,list)) {
            cout << list << endl;
            if (list.length() > 2) {
                head = list.substr(0, list.find("->"));
                wordList.push_back(head);
                list.erase(0,head.length());
                while (list.find("->") != string::npos) {
                    list.erase(0,2);
                    if(list.find("->") != string::npos){
                        node = list.substr(0,list.find("->"));
                        list.erase(0,node.length());
                    } else {
                        node = list;
                    }
                    wordWeight.first = node.substr(0, node.find(","));
                    wordWeight.second = atoi(node.erase(0, node.find(",")+1).c_str());
                    cout << "weightWord.first = " << wordWeight.first << " weightWord.second = "<< wordWeight.second << endl;
                    adjacencyList[head].push_back(wordWeight);
                }
            }
        }
    }
    else
    {
        cout<<"Error opening word list txt file"<<endl;
        return -1;
    }
    myfile.close();

    // Printing adjacency List and the weights
    /*for (auto a: adjacencyList_words) {
        cout << "head = " << a.first << ":";
        for (auto w: a.second) {
            cout << w << "->";
        }
        cout << endl;
    }

    cout << endl;

    for (auto a: adjacencyList_weights) {
        cout << "head = " << a.first << ":";
        for (auto w: a.second) {
            cout << w << "->";
        }
        cout << endl;
    }*/

    int test = Dijkstra(adjacencyList,wordList,"cords","woods");


    return 0;
}
