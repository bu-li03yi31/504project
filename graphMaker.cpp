#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <map>
#define filename "4-words4.txt"

using namespace std;

// A structure to represent an adjacency list node
struct AdjListNode
{
    int dest;
    int weight;
    struct AdjListNode* next;
};

// A structure to represent an adjacency list
struct AdjList
{
    struct AdjListNode *head;  // pointer to head node of list
};

// A structure to represent a graph. A graph is an array of adjacency lists.
// Size of array will be V (number of vertices in graph)
struct Graph
{
    int V;
    struct AdjList* array;
};

// A utility function to create a new adjacency list node
struct AdjListNode* newAdjListNode(int dest, int weight)
{
    struct AdjListNode* newNode =
            (struct AdjListNode*) malloc(sizeof(struct AdjListNode));
    newNode->dest = dest;
    newNode->weight = weight;
    newNode->next = NULL;
    return newNode;
}

// A utility function that creates a graph of V vertices
struct Graph* createGraph(int V)
{
    struct Graph* graph = (struct Graph*) malloc(sizeof(struct Graph));
    graph->V = V;

    // Create an array of adjacency lists.  Size of array will be V
    graph->array = (struct AdjList*) malloc(V * sizeof(struct AdjList));

    // Initialize each adjacency list as empty by making head as NULL
    int i;
    for (i = 0; i < V; ++i)
        graph->array[i].head = NULL;

    return graph;
}

// Adds an edge to an undirected graph
void addEdge(struct Graph* graph, int src, int dest, int weight)
{
    // Add an edge from src to dest.  A new node is added to the adjacency
    // list of src.  The node is added at the begining
    struct AdjListNode* newNode = newAdjListNode(dest, weight);
    newNode->next = graph->array[src].head;
    graph->array[src].head = newNode;

    // Since graph is undirected, add an edge from dest to src also
    newNode = newAdjListNode(src, weight);
    newNode->next = graph->array[dest].head;
    graph->array[dest].head = newNode;
}

// A utility function to print the adjacenncy list representation of graph
void printGraph(struct Graph* graph, vector<string>& wordList)
{
    int v;
    ofstream myfile;
    myfile.open ("4-words4_graph.txt");

    printf("Adjacency list of every node:\n");
    for (v = 0; v < graph->V; ++v)
    {
        struct AdjListNode* pCrawl = graph->array[v].head;
        //printf("%s", wordList[v]);
        cout << wordList[v];
        myfile << wordList[v];
        while (pCrawl)
        {
            //printf("-> %s,%d", wordList[pCrawl->dest],pCrawl->weight);
            cout << "->" << wordList[pCrawl->dest] << "," << pCrawl->weight;
            myfile << "->" << wordList[pCrawl->dest] << "," << pCrawl->weight;
            pCrawl = pCrawl->next;
        }
        printf("\n");
        myfile << "\n";
    }
    myfile.close();
}

// Driver program to test above functions
int main()
{
    vector<string> wordList {"words", "cords", "lords", "woods"};
    map<string, vector<string> > bucketList;
    string word;
    string bucket;
    string array[] = {"words", "cords", "lords", "woods"};
    for (int i =0; i< wordList.size(); i++) {
        for (int j=0; j<wordList[i].length(); j++) {
            bucket = wordList[i].substr(0,j) + '_' + wordList[i].substr(j+1,wordList[i].length()-1);
            bucketList[bucket].push_back(wordList[i]);
        }
    };

    int diffLetter_index, pos_w, pos_x;
    int weight;
    int V = wordList.size();
    struct Graph* graph = createGraph(V);
    for (auto b: bucketList){
        //cout << endl << b.first << " has the following " << b.second.size() <<  " words: ";
        if (b.first.size() > 1) {
            for (auto w: b.second){
                //cout << w << endl;
                for (auto x: b.second){
                    //cout << w << endl;
                    if (w != x){
                        diffLetter_index = b.first.find("_");
                        weight = abs(w[diffLetter_index] - x[diffLetter_index]);
                        pos_w = find(wordList.begin(), wordList.end(), w)-wordList.begin();
                        pos_x = find(wordList.begin(), wordList.end(), x)-wordList.begin();
                        addEdge(graph,pos_w,pos_x,weight);
                    }
                }
            }
        }
    }




//    ifstream myfile ("/Users/ashiragendelman/Documents/EC504/GraphMaker/4-words4.txt");
//    //ifstream myfile ("4-words4.txt");
//    if(myfile)
//    {
//        while (getline(myfile,word))
//        cout << word << endl;
//        wordList.push_back(word);
//    }
//    else
//    {
//        cout<<"Error opening word list txt file"<<endl;
//        return -1;
//    }
//    myfile.close();

    // create the graph given in above fugure
//    int V = 5;
//    struct Graph* graph = createGraph(V);
//    addEdge(graph, 0, 1,1);
//    addEdge(graph, 0, 4,4);
//    addEdge(graph, 1, 2,1);
//    addEdge(graph, 1, 3,2);
//    addEdge(graph, 1, 4,3);
//    addEdge(graph, 2, 3,1);
//    addEdge(graph, 3, 4,1);
//
//    // print the adjacency list representation of the above graph
    printGraph(graph,wordList);

    return 0;
}
