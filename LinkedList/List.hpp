#ifndef LIST
#define LIST

#include "Node.cpp"

class List {
public:
  List();
  List(int val);
  List(int size, int arr[]);

  Node* getHead();
  void setHead(Node* first);

  void printList();
  void makeEmpty();
  bool insert(int pos, Node* n);
  bool insert(int pos, int val);
  bool insertBeginning(Node* n);
  bool insertBeginning(int val);
  Node* find(int val);
  Node* remove(int val);
  Node* findAtIndex(int index);
  Node* findAtPosition(int pos);
  Node* removeAtIndex(int index);
  Node* removeAtPosition(int pos);


private:
  Node* head;
};

#endif
