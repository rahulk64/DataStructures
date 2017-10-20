#include "StackArray.cpp"
#include <iostream>
using namespace std;

int main() {
  StackArray stack1(2);
  cout << "Stack Created w/value 2!" << endl;
  stack1.printStack();

  cout << "Pushing '5' to the stack" << endl;
  stack1.push(5);
  stack1.printStack();

  cout << "Pushing '3' to the stack" << endl;
  stack1.push(3);
  stack1.printStack();

  cout << "-----------------------" << endl;

  cout << "Creating new stack as {1, 2, 3, 4}" << endl;
  int arr[4] = {1, 2, 3, 4};
  StackArray stack2(4, arr);
  stack2.printStack();

  cout << "Stack Size: ";
  cout << "size = " << stack2.getStackSize() << endl;

  cout << "Popping the stack" << endl;
  stack2.pop();
  stack2.printStack();

  cout << "Peeking element in the stack: ";
  cout << "peek = " << stack2.peek() << endl;

  cout << "StackTopIndex: " << stack2.getStackTopIndex() << endl;
}
