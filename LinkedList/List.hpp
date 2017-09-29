#ifndef LIST
#define LIST

#include "Node.cpp"

class List {
public:
  List(int val);
  List(int num = 0, int arr[] = { });

  Node* getHead();
  bool setHead(Node* first);

  void printList();
  bool makeEmpty();
  bool insert(int pos, Node* n);
  Node* find(int val);
  Node* remove(int val);
  Node* findAtIndex(int index);
  Node* removeAtIndex(int index);


private:
  Node* head;
};

#endif
