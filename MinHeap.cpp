#include "MinHeap.h"
//Builds a heap from a given array a[] of given size
MinHeap::MinHeap(int cap)
{
    heap_size = 0;
    capacity = cap;
    harr = new int[cap];
    words = new string[cap];
}

// A recursive method to heapify a subtree with root at given index
// This method assumes that the subtrees are already heapified
void MinHeap::MinHeapify(int i)
{
    int l = left(i);
    int r = right(i);
    int smallest = i;
    if (l < heap_size && harr[l] < harr[i])
        smallest = l;
    if (r < heap_size && harr[r] < harr[smallest])
        smallest = r;
    if (smallest != i)
    {
        swap(&harr[i], &harr[smallest]);
        swapWords(&words[i], &words[smallest]);
        MinHeapify(smallest);
    }
}

// Method to remove minimum element (or root) from min heap
pair<string,int > MinHeap::extractMin()
{
    if (heap_size <= 0)
        return make_pair("*", INT_MAX);
    if (heap_size == 1)
    {
        heap_size--;
        return make_pair(words[0], harr[0]);
    }

    // Store the minimum value, and remove it from heap
    int res = harr[0];
    string resSt = words[0];
    harr[0] = harr[heap_size-1];
    words[0] = words[heap_size-1];
    heap_size--;
    MinHeapify(0);

    return make_pair(resSt, res);
}

// Inserts a new key 'k'
void MinHeap::insertKey(string word, int k)
{
    if (heap_size == capacity)
    {
        cout << "\nOverflow: Could not insertKey\n";
        return;
    }

    // First insert the new key at the end
    heap_size++;
    int i = heap_size - 1;
    harr[i] = k;
    words[i] = word;

    // Fix the min heap property if it is violated
    while (i != 0 && harr[parent(i)] > harr[i])
    {
        swap(&harr[i], &harr[parent(i)]);
        swapWords(&words[i], &words[parent(i)]);
        i = parent(i);
    }
}

// Decreases value of key at index 'i' to new_val.  It is assumed that
// new_val is smaller than harr[i].
void MinHeap::decreaseKey(int i, int new_val)
{
    harr[i] = new_val;
    while (i != 0 && harr[parent(i)] > harr[i])
    {
        swap(&harr[i], &harr[parent(i)]);
        swapWords(&words[i], &words[parent(i)]);
        i = parent(i);
    }
}

// This function deletes key at index i. It first reduced value to minus
// infinite, then calls extractMin()
void MinHeap::deleteKey(int i)
{
    decreaseKey(i, INT_MIN);
    extractMin();
}

// A utility function to swap two elements
void swap(int *x, int *y)
{
    int temp = *x;
    *x = *y;
    *y = temp;
}

// A utility function to swap two words
void swapWords(string *left, string *right)
{
    string temp = *left;
    *left = *right;
    *right = temp;
}

// Driver program to test above functions
int main()
{
    MinHeap h(11);
    h.insertKey("words",3);
    h.insertKey("cords",2);
    h.deleteKey(1);
    h.insertKey("lords",15);
    h.insertKey("fords",5);
    h.insertKey("bords",4);
    h.insertKey("zords",45);
    pair<string, int> test1 = h.extractMin();
    pair<string, int> test2 = h.getMin();
    cout << test1.first << " ";
    cout << test1.second << " ";
    cout << test2.first << " ";
    cout << test2.second << " ";
    h.decreaseKey(2, 1);
    cout << h.getMin().first;
    cout << h.getMin().second;
    return 0;
}