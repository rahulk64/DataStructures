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
  Node* find(int val);
  bool insert(Node* n);
  Node* remove(int val);
  Node* findAtIndex(int index);
  Node* removeAtIndex(int index);


private:
  Node* head;
};

#endif
