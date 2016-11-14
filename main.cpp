#include"FibonacciHeap.h"
#include<iostream>
using namespace std;
int main() {
	int array[] = {7, 21, 18, 52, 38, 24, 17, 23, 39, 41};
	FibHeap testHeap = FibHeap();
	for (int i = 0; i < 10; i++) {
		type key = array[i];
		testHeap.insert(key);
	}
	FibNode* Min = testHeap.ExtractMin();
	FibNode* temp = Min->getnext();
	while (temp != Min) {
		testHeap.display(temp);
		temp = temp->getnext();
	}
	testHeap.display(temp);
	system("pause");
	return 0;
}