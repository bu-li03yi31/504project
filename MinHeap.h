// A C++ program to demonstrate common Binary Heap Operations
#include<iostream>
#include<climits>
#include <map>
using namespace std;

// Prototype of a utility function to swap two integers
void swap(int *x, int *y);
void swapWords(string *left, string *right);

// A class for Min Heap
class MinHeap
{
    map<string, int> wordsPostions;
    string *words; // pointer to array of elements in heap
    int *harr; // pointer to array of elements in heap
    int capacity; // maximum possible size of min heap
    int heap_size; // Current number of elements in min heap
public:
    // Constructor
    MinHeap(int capacity);

    // to heapify a subtree with root at given index
    void MinHeapify(int );

    int parent(int i) { return (i-1)/2; }

    int getSize() { return heap_size; }

    // to get index of left child of node at index i
    int left(int i) { return (2*i + 1); }

    // to get index of right child of node at index i
    int right(int i) { return (2*i + 2); }

    // to extract the root which is the minimum element
    pair<string,int > extractMin();

    // Decreases key value of key at index i to new_val
    void decreaseKey(int i, int new_val);

    //decreases key by word
    void decreaseKeyByWord(string word, int val);

    // Returns the minimum key (key at root) from min heap
    pair<string,int > getMin() { return make_pair(words[0], harr[0]); }

    // Deletes a key stored at index i
    void deleteKey(int i);

    // Inserts a new key 'k'
    void insertKey(string word, int k);
};
