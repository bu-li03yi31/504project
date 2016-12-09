
#include <iostream>
#include <fstream>
#include <vector>
#include <map>
#include <unordered_set>
#include"FibonacciHeap.h"
using namespace std;
ofstream out("/Users/sunmin/Desktop/EC504/Clion/504project/fib-output.txt");

//Created by Yi Li 2016 fall
//Modified by Yi Li, Avi Klunser, Min Sun, Xi Zhou
int Dijkstra(map<string, vector<pair<string,int >> >& adjacencyList
        , vector<string>& wordList, string start, string stop){
    /* ****** initializing everything ***** */
    //store path sum of each node
    map<string, int> dist;
    //store parent of each node
    map<string, string> prev;

    //initialize the visited set
    //to store the visited nodes later
    unordered_set<string> visited;
    //initialize fib-pq
    FibHeap Fib_pq = FibHeap();
    for(int i = 0; i < wordList.size(); i++){
        if(start.compare(wordList[i]) == 0){//starting point
            dist[wordList[i]] = 0; // the distance from starting point to itself is zero
            Fib_pq.insert(0, wordList[i]);//add the starting point to our pq
        }else{
            dist[wordList[i]] = INT_MAX;
            //adding each node to the pq, each weight is max_int
            Fib_pq.insert(INT_MAX, wordList[i]);
        }
        prev[wordList[i]] = "*";//parent of each node is always null initially
    }
	
    /* ****** tracing every path ***** */
    pair<string, int> tmp;// a buffer to store node
	FibNode *temp = Fib_pq.getMin();
    while(Fib_pq.getMin()){
        string current = Fib_pq.getMin()->word;
        FibNode *Min = Fib_pq.ExtractMin();
		Fib_pq.setMin(Min);
		vector<vector<int>> res;
        for(int j = 0; dist[current] != INT_MAX && j < adjacencyList[current].size(); j ++){
            string neighbour = adjacencyList[current][j].first;
            tmp = make_pair(neighbour, dist[neighbour]);
            const bool is_in = visited.find(neighbour) != visited.end();
            if(!is_in){//if this neighbour has never been visited
                //adjacencyList[current][j].second is the weight between neighbour and current
                if(dist[neighbour] > adjacencyList[current][j].second + dist[current]){
                    //update the weight in dist array with the smaller path sum
                    dist[neighbour] = adjacencyList[current][j].second + dist[current];
                    prev[neighbour] = current; // update the parent

                    Fib_pq.DecreaseKey(Fib_pq.search(neighbour), dist[neighbour]);
                }
            }
        }
        visited.insert(current);//set current node to be visited
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
	
	out << path << endl << "\n";
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

    ifstream myfile("/Users/yil/Desktop/504-project-repo/504project/5-words53_graph.txt");
    if(myfile)
    {
        while (getline(myfile,list)) {
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
	for (int i = 0; i < wordList.size(); i++) {
		for (int j = i + 1; j < wordList.size(); j++) {
				int distance = Dijkstra(adjacencyList, wordList, wordList[i], wordList[j]);
				
		}
	}
    
    return 0;
}
