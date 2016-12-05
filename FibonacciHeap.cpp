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
	if (node == NULL) {
		return;
	}
	FibNode* c = node->next;
	while (c != node) {
		c->marked = false;
		c->parent = NULL;
		c = c->next;
	}
	c->marked = false;
	c->parent = NULL;
	return;
}

FibNode *FibHeap::Consolidate(FibNode* z) {
	vector<FibNode* > A(64, NULL);
	int i = 0;
	//FibNode *w = head;
//	FibNode *x;
	FibNode *t;
//	FibNode *y;
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
			z->prev->next = z->next;
			z->next->prev = z->prev;
			if (zchild) {                           
				FibNode *temp = zchild->prev;
				z = zchild;
				z->prev = zprev;
				zprev->next = z;
				if (temp == zchild) {               //only one child
					z->next = znext;
					znext->prev = z;
				}
				else {
					temp->next = znext;
					znext->prev = temp;
				}
			}
			else {                                   //no child
				
				if (z == head) head = z->next;
				if (z == tail) tail = z->prev;
				head->prev = tail;
				tail->next = head;
			}
		}
		
		if (z == z->next) {
			Min = z;
		}
		else {
			Min = z->next;
			Min = Consolidate(z->next);            //z->next will not change, but attributes in z->next will change
		}
		NodeNum--;
		return Min;
	}
	return Min;
}

void FibHeap::display(FibNode* node, vector<vector<type>>& res, int line) {
	if (node == NULL) return;
	
	//printf("%d ", node->key);
	vector<type> temp;
	if (line != 0) {
		vector<type> tmp(res[0].size(), 0);
		temp = tmp;
	}
	if(res.size() <= line) res.push_back(temp);
	for (int i = 0; i < res.size(); i++) {
		if(i != line) res[i].push_back(0);
	}
	res[line].push_back(node->key);
	if (node->child) {
		FibNode* t = node->child;
		//printf("(");
		for (int i = 0; i < node->degree; i++) {
			display(t, res, line + 1);
			t = t->next;
		}
		//printf("\b) ");
	}
	
}


void FibHeap::DecreaseKey(FibNode *node, type k) {
	if (k > node->key) {
		printf("new key is greater than current key");
		return;
	}
	node->key = k;
	FibNode *y = node->parent;              //y : parent of x
	if (y != NULL && node->key < y->key) {
		cut(node, y);
		CascadingCut(y);
	}
	if (node->key < Min->key) {
		Min = node;
	}
}

FibNode* FibHeap::cut(FibNode *x, FibNode *y) {
	FibNode *MinNext = Min->next;
	/*remove x from the child list of y, decrementing y degree*/
	//y has only one child
	if (x->next == x) {
		y->child = NULL;
	}
	else {
		FibNode *xprev = x->prev;
		FibNode *xnext = x->next;
		xprev->next = xnext;
		xnext->prev = xprev;
		if (y->child == x) y->child = xnext;              //if x is y's child, let xnext be y's child
	}
	y->degree -= 1;
	Min->next = x;
	x->prev = Min;
	x->next = MinNext;
	MinNext->prev = x;
	x->parent = NULL;
	x->marked = false;
	return Min;
}

FibNode* FibHeap::CascadingCut(FibNode *y) {
	FibNode *z = y->parent;
	if (z) {
		if (y->marked == false) {
			y->marked = true;
		}
		else {
			cut(y, z);
			CascadingCut(z);
		}
	}
	return Min;
}

FibNode* FibHeap::search(type key) {
	FibNode* temp = Min->getnext();
	while (temp != Min) {
		FibNode* tmp = SearchHelper(key, temp);
		if (tmp) {
			return tmp;
		}
		temp = temp->getnext();
	}
	return SearchHelper(key, temp);
}

FibNode* FibHeap::SearchHelper(type key, FibNode* z) {
	if (z->key == key) {
		return z;
	}
	FibNode* child = z->child;
	for (int i = 0; i < z->degree; i++) {
		FibNode* target = SearchHelper(key, child);
		if (target != NULL) return target;
		child = child->next;
	}
	return NULL;
}