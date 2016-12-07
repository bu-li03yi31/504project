






#ifndef LinkedList_h
#define LinkedList_h

#include <iostream>
#include <string>
using namespace std;


struct node
{
    string word;
    int dist;
    node * next;
};


class LinkedList
{
private:

    node * head;
    int listLength;
    
public:

    LinkedList();
    
    bool insertNode( node * newNode, int position );
    
    bool removeNode( int position );

    bool updateNodeDist( string wordFind, int newDist );

    int findMinNode();

    void printList();

    ~LinkedList();
};

#endif