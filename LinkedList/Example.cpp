#include "List.cpp"
#include<iostream>

using namespace std;

int main() {
  List list1(4);
  cout << "Created List" << endl;
  list1.printList();

  cout << "Inserting 8 at beginning" << endl;
  list1.insertBeginning(8);
  list1.printList();

  cout << "Inserting 3 after 8" << endl;
  list1.insert(1, 3);
  list1.printList();

  cout << "Inserting new node (5) at beginning" << endl;
  Node* newNode = new Node;
  newNode->setValue(5);
  list1.insertBeginning(newNode);
  list1.printList();

  cout << "Inserting new node (7) at position 3" << endl;
  Node* newNode2 = new Node;
  newNode2->setValue(7);
  list1.insert(3, newNode2);
  list1.printList();

  cout << "Getting size of Linked List: ";
  cout << "size = " << list1.getSize() << endl;

  cout << "Removing value 8" << endl;
  list1.remove(8);
  list1.printList();

  cout << "Removing value at index 3" << endl;
  list1.removeAtIndex(3);
  list1.printList();

  cout << "Removing value at position 2" << endl;
  list1.removeAtPosition(2);
  list1.printList();

  cout << "Removing first node" << endl;
  list1.removeAtIndex(0);
  list1.printList();

  cout << "Deleting List" << endl;
  list1.makeEmpty();
  list1.printList();

  cout << "---------------------------------------" << endl;

  cout << "Creating new List from 1-10" << endl;
  int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
  List list2(10, arr);
  list2.printList();
  cout << list2.getHead()->getValue() << endl;

  cout << "Manually setting head to position 2" << endl;
  list2.setHead(list2.getHead()->getNext()); //Note: bad practice; for demonstration only
  list2.printList();

  cout << "Returning node with value 5: ";
  Node* myNode = list2.find(5);
  cout << "value = " << myNode->getValue() << endl;

  cout << "Returning node at position 7: ";
  myNode = list2.findAtPosition(7);
  cout << "value = " << myNode->getValue() << endl;

  cout << "Returning node at index 2: ";
  myNode = list2.findAtIndex(2);
  cout << "value = " << myNode->getValue() << endl;

  return 0;
}
