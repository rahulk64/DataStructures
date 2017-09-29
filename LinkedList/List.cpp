#include "List.hpp"
using namespace std;

List::List(int val) {
  Node first(val);
  head = &first;
}

List::List(int num, int arr[]) {
  Node current(arr[0]);
  for(int i = 1; i < num; i++) {
    Node temp(arr[i]);
    current.next = &temp;
    current = current.next;
  }
}

Node* List::getHead() {
  return head;
}

void List::setHead(Node* first) {
  head = first;
}

void List::printList() {
  Node* curr = head;
  if(curr == NULL) {
    cout << "Empty List" << endl;
    return;
  }

  while(curr !=NULL) {
    cout << curr->val << ", ";
    curr = curr.next;
  }
  cout << endl;
}

bool List::makeEmpty() {

}

Node* List::find(int val) {

}

bool List::insert(Node* n) {

}

Node* List::remove(int val) {

}

Node* List::findAtIndex(int index) {

}

Node* List::removeAtIndex(int index) {

}
