#include"FibonacciHeap.h"
void FibHeap::insert(type key) {
	FibNode *newnode = new FibNode(key);
	if (!head) {                           //heap  is empty;
		head = newnode;
		tail = newnode;
		tail->next = head;
		head->prev = tail;
		Min = newnode;
		NodeNum += 1;
		return;
	}
	tail->next = newnode;
	newnode->prev = tail;
	newnode->next = head;
	tail = newnode;
	head->prev = tail;
	tail->next = head;
	NodeNum += 1;
	if (Min->key > key) {
		Min = newnode;
	}
	return;
}

void FibHeap::unmarkandunparent(FibNode* node) {
	if (node == nullptr) {
		return;
	}
	FibNode* c = node;
	while (c != node) {
		c->marked = false;
		c->parent = nullptr;
		c = c->next;
	}
}

FibNode *FibHeap::Consolidate(FibNode *z) {
	FibNode *A[64];
	for (int i = 0; i < 64; i++) {
		A[i] = NULL;
	}
	int i = 0;
	//FibNode *w = head;
	FibNode *x;
	FibNode *t;
	FibNode *y;
	//FibNode *temp = w;
	//int d;
	while (true) {
		
		if (A[z->degree] != NULL) {
			t = A[z->degree];             //t and z has same degree
			if (t == z) break;
			A[z->degree] = NULL;
			if (z->key < t->key) {
				t->prev->next = t->next;
				t->next->prev = t->prev;
				
				//add t to z's children list
				FibNode *zchild = z->child;
				if (zchild) {
					FibNode *temp = zchild->prev;
					temp->next = t;
					t->prev = temp;
					zchild->prev = t;
					t->next = zchild;
				}
				else {
					z->child = t;
					t->next = t;
					t->prev = t;
				}
				t->parent = z;
				z->degree += 1;
			}
			else {
				z->prev->next = z->next;
				z->next->prev = z->prev;
				
				//add z to t's children list
				FibNode *tchild = t->child;
				FibNode *znext = z->next;
				if (tchild) {
					FibNode *temp = tchild->prev;
					temp->next = z;
					z->prev = temp;
					tchild->prev = z;

					z->next = tchild;
					z->parent = t;
				}
				else {
					t->child = z;
					z->next = z;
					z->prev = z;
				}
				
				
				z->parent = t;
				t->degree += 1;
				if (A[t->degree] == NULL) {
					A[t->degree] = t;
					z = znext;
				}
				else {
					z = t;
					t = A[t->degree];
				}
				if (z->degree != t->degree) A[z->degree] = NULL;
			}
			continue;
		}
		else {
			A[z->degree] = z;
		}
		z = z->next;
	}
	FibNode *min = z;
	FibNode *ztemp = z->next;
	while (ztemp != z) {
		if (z->key < min->key) min = ztemp;
		ztemp = ztemp->next;
	}
	if (ztemp->key < min->key) min = ztemp;
	Min = min;
	return Min;
}


FibNode *FibHeap::ExtractMin() {
	FibNode *z = Min;
	if (z) {
		unmarkandunparent(z->child);
		FibNode *zchild = z->child;
		FibNode *znext = z->next;
		FibNode *zprev = z->prev;
		if (z->next == z) {
			z = z->child;
		}
		else {
			if (zchild) {                           
				FibNode *temp = zchild->prev;
				z = zchild;
				z->prev = zprev;
				if (temp == zchild) {               //only one child
					z->next = znext;
				}
				else {
					temp->next = znext;
				}
			}
			else {                                   //no child
				z->prev->next = z->next;
				z->next->prev = z->prev;
				if (z == head) head = z->next;
				if (z == tail) tail = z->prev;
				head->prev = tail;
				tail->next = head;
			}
		}
		
		if (z == z->next) {
			Min = nullptr;
		}
		else {
			Min = z->next;
			Min = Consolidate(z->next);
		}
		NodeNum--;
		return Min;
	}
}

void FibHeap::display(FibNode* node) {
	if (node == NULL) return;
	
	printf("%d ", node->key);
	if (node->child) {
		FibNode* temp = node->child;
		printf("(");
		for (int i = 0; i < node->degree; i++) {
			//printf("%d,", temp->key);
			display(temp);
			temp = temp->next;
		}
		printf("\b) ");
	}
	
}