#ifndef STACKLIST
#define STACKLIST
using namespace std;

#include "LinkedList/Node.cpp"

class StackList {
public:
  StackList();
  StackList(int num);
  StackList(int size, int arr[]);

  bool isEmpty();
  void printStack();
  bool push(int item);
  Node* pop();
  Node* peek();
  Node* getStackHead();
  bool setHead(Node* node);

private:
  Node* head;
};

#endif
