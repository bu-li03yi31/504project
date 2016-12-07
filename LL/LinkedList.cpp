#include "LinkedList.h"

LinkedList::LinkedList()
{
    cout << "\nEntering Constructor ..." << endl;
    head = new node;
    head -> word = "head (contains no dictionary word)";
    head -> dist = 0;
    head -> next = NULL;
    listLength = 0;
    cout << "Success: head node created. listLength set to 0." << endl;
}


bool LinkedList::insertNode( node * newNode, int position )
{
    cout << "\nEntering insertNode @ " << position <<  endl;
    if ((position <= 0) || (position > listLength + 1))
    {
        cout << "nError: the given position is out of range.n";
        return false;
    }
    if (head -> next == NULL)
    {
        head -> next = newNode;
        newNode -> next = NULL;
        listLength++;
        cout << "Success: added '" << newNode -> word << "' to position " << position << ".\n";
        cout << "listLength = " << listLength << endl;
        return true;
    }
    int count = 1;
    node * p = head;
    node * q = head;
    while (q->next != NULL)
    {
        if (count == position)
        {
            p -> next = newNode;
            newNode -> next = q;
            listLength++;
            cout << "Success: added '" << newNode -> word << "' to position " << position << ".\n";
            cout << "listLength = " << listLength << endl;
            return true;
        }
        p = q;
        q = p -> next;
        count++;
    }
    if (count == position)
    {
        p -> next = newNode;
        newNode -> next = NULL;
        listLength++;
        cout << "Success: added '" << newNode -> word << "' to position " << position << ".\n";
        cout << "listLength = " << listLength << endl;
        return true;
    }
    cout << "Error: word node was not added to list." << endl;
    return false;
}


bool LinkedList::removeNode( int position )
{
    cout << "\nEntering removeNode..." << endl;
    if ( (position <= 0) || (position > listLength + 1) )
    {
        cout << "Error: the given position is out of range." << endl;
        return false;
    }
    if (head -> next == NULL)
    {
        cout << "Error: there is nothing to remove." << endl;
        return false;
    }
    
    int count = 1;
    node * p = head;
    node * q = head;
    while (q->next != NULL)
    {
        if (count == position)
        {
            p -> next = q -> next;
            delete q;
            listLength--;
            cout << "Success: node at position " << position << " was deleted." << endl;
            cout << "listLength = " << listLength << endl;
            return true;
        }
        p = q;
        q = p -> next;
        count++;
    }
    cout << "Error: nothing was removed from the list." << endl;
    return false;
}


bool LinkedList::updateNodeDist(string wordFind, int newDist)
{
    node * p = head;
    node * q = head;
    while (q->next != NULL)
    {
        if (q->word == wordFind)
        {
            q->dist = newDist;
            return true;
        }
        p = q;
        q = p->next;
    }
    return false;
}


int LinkedList::findMinNode()
{
    int minPos = 0;
    int minDist = numeric_limits<int>::max();
    node * p = head;
    node * q = p->next;
    int p_ind = 1;
    while(q->next != NULL)
    {
        if(q->dist < minDist)
        {
            minPos = p_ind;
            minDist = q->dist;
        }
        p_ind++;
    }
    cout << "nError: Min wasn't removed from the list.n";
    return minPos;
}


void LinkedList::printList()
{
    cout << "\nEntered printList..." << endl;
    int count = 0;
    node * p = head;
    node * q = head;
    cout << "\n---------------------\n";
    cout << " Word list\n";
    while (q->next != NULL)
    {
        p = q;
        cout << "---------------------\n";
        cout << "\t position: " << count << "\n";
        cout << "\t word: " << p -> word << "\n";
        cout << "\t dist: " << p -> dist << "\n";
        q = p -> next;
        count++;
    }
}


LinkedList::~LinkedList()
{
    cout << "\nEntering Destructor..." << endl;
    node * p = head;
    node * q = head;
    while (q->next != NULL)
    {
        p = q;
        q = p -> next;
        delete p;
    }
    cout << "Success: list is deleted." << endl;
}