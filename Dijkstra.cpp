
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

//Created by Yi Li 2016 fall
//Modified by Yi Li, Avi Klunser, Min Sun, Xi Zhou
int Dijkstra(map<string, vector<pair<string,int >> >& adjacencyList
        , vector<string>& wordList, string start, string stop){
    /* ****** initializing everything ***** */
    //store path sum of each node
    map<string, int> dist;
    //store parent of each node
    map<string, string> prev;
    //our priority queue here

    //overriding the comparator of pair pq
    struct QComparator
    {
        bool operator() (const std::pair<string, int>& left, const std::pair<string, int>& right) const
        {
            if(left.second == right.second){
                return left.first.compare(right.first) != 0;
            }else{
                return left.second < right.second;
            }
        }
    };
    //initialize the visited set
    //to store the visited nodes later
    unordered_set<string> visited;
    //initialize our pq by using customized comparator
    set<pair<string, int>, QComparator> pq;
    for(int i = 0; i < wordList.size(); i++){
        if(start.compare(wordList[i]) == 0){//starting point
            dist[wordList[i]] = 0; // the distance from starting point to itself is zero
            pq.insert(make_pair(wordList[i], 0));//add the starting point to our pq
        }else{
            dist[wordList[i]] = numeric_limits<int>::max();
            //adding each node to the pq, each weight is max_int
            pq.insert(make_pair(wordList[i], numeric_limits<int>::max()));
        }
        prev[wordList[i]] = "*";//parent of each node is always null initially
    }

    /* ****** tracing every path ***** */
    pair<string, int> tmp;// a buffer to store node
    while(!pq.empty()){
        string current = pq.begin() -> first;
        //cout << current << endl;
        pq.erase(pq.begin());//pops out the smallest item
        for(int j = 0; dist[current] != numeric_limits<int>::max() && j < adjacencyList[current].size(); j ++){
            string neighbour = adjacencyList[current][j].first;
            tmp = make_pair(neighbour, dist[neighbour]);
            const bool is_in = visited.find(neighbour) != visited.end();
            if(!is_in){//if this neighbour has never been visited
                //adjacencyList[current][j].second is the weight between neighbour and current
                if(dist[neighbour] > adjacencyList[current][j].second + dist[current]){
                    //update the weight in dist array with the smaller path sum
                    dist[neighbour] = adjacencyList[current][j].second + dist[current];
                    prev[neighbour] = current; // update the parent

                    //decrease the key of the neighbour to the latest path sum
                    pq.erase(tmp);
                    pq.insert(make_pair(neighbour, dist[neighbour]));
                }
                visited.insert(adjacencyList[current][j].first);//set current node to be visited
            }
        }
    }
    /* ***** print out the shortest path and returns the value ***** */
    string path = stop;
    path += "<-";
    string s = stop;
    while(s.compare(start) != 0){
        path = path + prev[s];
        if(prev[s].compare(start) != 0 && prev[s].compare("*") != 0){
            path = path + "<-";
        }
        string previous = prev[s];
        s = previous;
        if(previous.compare("*") == 0) break;
    }
    cout << path << endl;
    //return the path sum of the ending point
    return dist[stop];
};

int main() {
    string list;
    string node;
    string head;
    map<string, vector<pair<string,int >> > adjacencyList;
    vector<string> wordList;
    pair< string, int> wordWeight;

    ifstream myfile ("/Users/yil/Desktop/504-project-repo/504project/5-words53_graph.txt");
    if(myfile)
    {
        while (getline(myfile,list)) {
            //cout << list << endl;
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
    int distance = Dijkstra(adjacencyList,wordList,"cords","graph");
    cout << distance << endl;
    return 0;
}
