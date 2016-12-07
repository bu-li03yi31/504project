#include "LinkedList.h"
#include <iostream>
#include <string>
using namespace std;

int main(){

    node *A = new node;
    A -> word = "Apple";
    A -> dist = 17;

    node * B = new node;
    B -> word = "Bumps";
    B -> dist = 22;

    node * C = new node;
    C -> word = "Camps";
    C -> dist = 12;

    node * D = new node;
    D -> word = "Drake";
    D -> dist = 1;

    node * E = new node;
    E -> word = "Elast";
    E -> dist = 5;

    LinkedList myList;
    cout << "made list" << endl;
    myList.insertNode(A, 1);
    myList.insertNode(B, 2);
    myList.insertNode(C, 3);
    myList.insertNode(D, 4);
    myList.printList();
    
    myList.removeNode(3);
    myList.insertNode(E, 4);
    myList.printList();

    myList.removeNode(4);
    myList.removeNode(3);
    myList.removeNode(2);
    myList.removeNode(1);
    myList.printList();
    
   	return 0;
}