#ifndef FIBONACCIHEAP_H
#define FIBONACCIHEAP_H
#include<iostream>
#include<vector>
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
	FibNode(type data) :key(data), degree(0), parent(NULL), prev(NULL), next(NULL), marked(false), child(NULL){}
	FibNode* getnext() {
		return this->next;
	}
	FibNode* getchild() {
		return this->child;
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
	//FibNode* Consolidate(FibNode* &z);
	void unmarkandunparent(FibNode* node);
	FibNode * Consolidate(FibNode * z);
	void display(FibNode *node, vector<vector<type>>& res, int line);
	void DecreaseKey(FibNode *node, type k);
	FibNode* cut(FibNode *x, FibNode *y);
	FibNode* CascadingCut(FibNode *y);
	FibNode* getMin(){
		return this->Min;
	}
	FibNode* search(type key);
	FibNode* SearchHelper(type key, FibNode* z);
};

#endif
