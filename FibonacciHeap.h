#ifndef FIBONACCIHEAP_H
#define FIBONACCIHEAP_H
#include<iostream>
#define type int 
using namespace std;

class FibNode {
public:
	type key;
	int degree;
	FibNode *parent;
	FibNode *prev;
	FibNode *next;
	FibNode *child;
	bool marked;
	FibNode(type data) :key(data), degree(0), parent(NULL), prev(NULL), next(NULL), marked(false) {}
	FibNode* getnext() {
		return this->next;
	}
};



class FibHeap {
private:
	int NodeNum;
	int MaxDegree;
	FibNode *Min;
	FibNode *head;
	FibNode *tail;
public:
	FibHeap() :NodeNum(0), MaxDegree(0), Min(NULL), head(NULL), tail(NULL) {}
	//~FibHeap();
	void insert(type key);
	FibNode *ExtractMin();
	FibNode* Consolidate(FibNode *z);
	void unmarkandunparent(FibNode* node);
	void display(FibNode *node);
};

#endif
