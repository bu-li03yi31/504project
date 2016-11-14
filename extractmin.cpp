#include"FibonacciHeap.h"

#include<iostream>
using namespace std;
int main() {
	int array[] = {7, 21, 18, 2098, 6};
	FibHeap testHeap = FibHeap();
	for (int i = 0; i < 5; i++) {
		type key = array[i];
		testHeap.insert(key);
	}
    printf("\n");
	FibNode* Min = testHeap.ExtractMin();
	FibNode* temp = Min->getnext();
	while (temp != Min) {
		testHeap.display(temp);
		temp = temp->getnext();
	}
	testHeap.display(temp);
	printf("\n");
	Min = testHeap.ExtractMin();
	temp = Min;
	testHeap.display(temp);
	//system("pause");
	return 0;
}