#include"LinkedList.h"

LinkedList::LinkedList()
{
	//cout << "\nEntering Constructor ..." << endl;
	head = new node();
	head->word = "head (contains no dictionary word)";
	head->dist = 0;
	head->next = NULL;
	listLength = 0;
	//cout << "Success: head node created. listLength set to 0." << endl;
}


bool LinkedList::insertNode(node * newNode)
{
	//cout << "\nEntering insertNode..." << endl;
	node * p = head;
	while (p->next != NULL)
	{
		p = p->next;
	}
	p->next = newNode;
	newNode->next = NULL;
	listLength++;
	//cout << "Success: added '" << newNode->word << ".\n";
	//cout << "listLength = " << listLength << endl;
	return true;
}

bool LinkedList::removeNode(string delWord)
{
	//cout << "\nEntering removeNode..." << endl;
	node *p = head;
	while (p->next != NULL)
	{
		if(p->next->word==delWord)
		{
			p->next = p->next->next;
			listLength--;
	//		cout << "Success: removed " << delWord << ".\n";
	//		cout << "listLength = " << listLength << endl;
			return true;
		}
		p = p->next;
	}
	//cout << "Failure: " << delWord << " wasn't removed.\n";
	return false;
}

bool LinkedList::updateNodeDist(string wordFind, int newDist)
{
	//cout << "\nEntered printList..." << endl;
	node * p = head;
	while(p->next != NULL)
	{
		if (p->next->word==wordFind)
		{
	//		cout << "Success: updated " << wordFind << " from " << p->next->dist << " to " << newDist << ".\n";
			p->next->dist = newDist;
			return true;
		}
		p = p->next;
	}
	//cout << "Failure: " << wordFind << " wasn't updated.\n";
	return false;
}

string LinkedList::findMinNode()
{
	//cout << "\nEntered findMinNode..." << endl;
	int min = INT_MAX;
	string min_word = "none";
	node * p = head;
	while(p->next != NULL)
	{
		if (p->next->dist<=min)
		{
			min = p->next->dist;
			min_word = p->next->word;
		}
		p = p->next;
	}
	//cout << "Success: updated min to " << min_word << " with dist of " << min <<".\n";
	return min_word;
}

void LinkedList::printList()
{
	cout << "\nEntered printList..." << endl;
	int pos = 0;
	node * p = head;
	cout << "\n---------------------\n";
	cout << " Word list\n";
	while(p->next != NULL)
	{
	 	cout << "---------------------\n";
		cout << "\t position: " << pos << "\n";
		cout << "\t word: " << p->word << "\n";
		cout << "\t dist: " << p->dist << "\n";
		p = p->next;
		pos++;
	}
 	cout << "---------------------\n";
 	cout << "\t position: " << pos << "\n";
	cout << "\t word: " << p->word << "\n";
	cout << "\t dist: " << p->dist << "\n";
}

bool LinkedList::hasNodes()
{
	if (listLength > 0)
		return true;
	else
		return false;

}