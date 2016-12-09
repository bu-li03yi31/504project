#ifndef LinkedList_h
#define LinkedList_h

#include <iostream>
#include <string>
#include <limits>
using namespace std;


struct node
{
	string word;
	int dist;
	node * next;
	//node() : dist(0), next(NULL) {}
};


class LinkedList
{
private:

	node * head;
	int listLength;

public:

	LinkedList();

	bool insertNode(node * newNode);

	bool removeNode(string delWord);

	bool updateNodeDist(string wordFind, int newDist);

	string findMinNode();

	void printList();

	bool hasNodes();

	//~LinkedList();
};

#endif
