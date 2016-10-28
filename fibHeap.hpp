template <class V> class FibHeap;

template <class V> struct node {
private:
  node<V>* prev;
  node<V>* next;
  node<V>* child;
  node<V>* parent;
  V val;
  int degree;
  bool marked;
public:
  friend class FibHeap<V>;
  node<V>* getPrev() {return prev;}
  node<V>* getNext() {return next;}
  node<V>* getChild() {return child;}
  node<V>* getParent() {return parent;}
  V getValue() {return value;}
  bool isMarked() {return marked;}

  bool hasChildren() {return child;}
  bool hasParent() {return parent;}
};

template <class V> class FibHeap {
protected:
    node<V>* heap;

public:

private:

};
