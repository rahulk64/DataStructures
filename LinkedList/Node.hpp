#ifndef NODE
#define NODE

class Node {
public:
  Node(int v = 0);
  Node(int v, Node* n);

  int getValue();
  void setValue(int v);

  Node* getNext();
  void setNext(Node* n);

private:
  int val;
  Node* next;
};

#endif
