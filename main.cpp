#include"FibonacciHeap.h"
#include<iostream>
#include<iomanip>
using namespace std;
int main() {
	int array[] = {7, 21, 18, 52, 38, 24, 17, 23, 39, 41};
	FibHeap testHeap = FibHeap();
	for (int i = 0; i < sizeof(array)/sizeof(int); i++) {
		type key = array[i];
		testHeap.insert(key);
	}
	FibNode* Min = testHeap.ExtractMin();
	FibNode* temp = Min->getnext();
	vector<vector<type>> res;
	vector<vector<type>> tmp;
	while (temp != Min) {
		testHeap.display(temp, res, 0);
		temp = temp->getnext();
	}
	testHeap.display(temp, res, 0);
	for (int i = 0; i < res.size(); i++) {
		for (int j = 0; j < res[i].size(); j++) {
			if (res[i][j] == 0) cout << setw(5) << "";
			//else printf("%d ", res[i][j]);
			else cout << setw(5) << res[i][j] ;
		}
		printf("\n");
	}
	printf("\n");
	/*Min = testHeap.ExtractMin();
	temp = Min->getnext();
	res = tmp;
	while (temp != Min) {
		testHeap.display(temp, res, 0);
		temp = temp->getnext();
	}
	testHeap.display(temp, res, 0);
	for (int i = 0; i < res.size(); i++) {
		for (int j = 0; j < res[i].size(); j++) {
			if (res[i][j] == 0) printf("  ");
			else printf("%d ", res[i][j]);
		}
		printf("\n");
	}*/
	
	testHeap.DecreaseKey(testHeap.search(21), 15);
	testHeap.DecreaseKey(testHeap.search(38), 14);
	/*print out heap*/
	Min = testHeap.getMin();
	temp = Min->getnext();
	res = tmp;
	while (temp != Min) {
		testHeap.display(temp, res, 0);
		temp = temp->getnext();
	}
	testHeap.display(temp, res, 0);
	for (int i = 0; i < res.size(); i++) {
		for (int j = 0; j < res[i].size(); j++) {
			if (res[i][j] == 0) cout << setw(5) << "" ;
			//else printf("%d ", res[i][j]);
			else cout << setw(5) << res[i][j];
		}
		printf("\n");
	}

    //system("pause");
	return 0;
}