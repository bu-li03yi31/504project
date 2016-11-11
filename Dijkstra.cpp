
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <fstream>
#include <string.h>
#include <vector>
#include <map>
#include <tuple>

using namespace std;


int Dijkstra(map<string, vector<string>>& adjacencyList_words, map<string, vector<int>>& adjacencyList_weights, string start, string stop){

    string *prev = new string[adjacencyList_weights.size()];
    string *dist = new string[adjacencyList_weights.size()];
    string start_index;
    string stop_index;

    for (int i =0; i<adjacencyList_weights.size(); i++){
        prev[i] = "none";
        dist[i] = 10000000;
    }
    start_index = adjacencyList_words.find(start);
    stop_index = adjacencyList_words.find(stop);
    dist[start_index] = 0;


    delete[] prev;
    delete[] dist;
};

int main() {
    string list;
    string node;
    string head;
    map<string, vector<string> > adjacencyList_words;
    map<string, vector<int> > adjacencyList_weights;

    ifstream myfile ("/Users/ashiragendelman/Documents/EC504/GraphMaker/4-words4_graph.txt");
    if(myfile)
    {
        while (getline(myfile,list)) {
            cout << list << endl;
            if (list.length() > 2) {
                head = list.substr(0, list.find("->"));
                list.erase(0,head.length());
                while (list.find("->") != string::npos) {
                    list.erase(0,2);
                    if(list.find("->") != string::npos){
                        node = list.substr(0,list.find("->"));
                        list.erase(0,node.length());
                    } else {
                        node = list;
                    }
                    //cout << node << endl;
                    adjacencyList_words[head].push_back(node.substr(0, node.find(",")));
                    adjacencyList_weights[head].push_back(atoi(node.erase(0, node.find(",")+1).c_str()));
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
    for (auto a: adjacencyList_words) {
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
    }





    return 0;
}