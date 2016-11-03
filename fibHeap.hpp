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
    FibonacciHeap() {
        heap=_empty();
    }
    virtual ~FibonacciHeap() {
        if(heap) {
            _deleteAll(heap);
        }
    }
    node<V>* insert(V value) {
        node<V>* ret=_singleton(value);
        heap=_merge(heap,ret);
        return ret;
    }
    void merge(FibonacciHeap& other) {
        heap=_merge(heap,other.heap);
        other.heap=_empty();
    }

    bool isEmpty() {
        return heap==NULL;
    }

    V getMinimum() {
        return heap->value;
    }

    V extractMinimum() {
        node<V>* old=heap;
        heap=_removeMinimum(heap);
        V ret=old->value;
        delete old;
        return ret;
    }

    void decreaseKey(node<V>* n,V value) {
        heap=_decreaseKey(heap,n,value);
    }

    node<V>* find(V value) {
        return _find(heap,value);
    }
private:

};
