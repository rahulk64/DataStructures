#include "List.hpp"
using namespace std;

List::List(int val) {
  Node first(val);
  head = &first;
}

List::List(int num = 0, int arr[] = { }) {
  if(num == 0) {
    head = NULL;
    return;
  }

  Node current(arr[0]);
  for(int i = 1; i < num; i++) {
    Node temp(arr[i]);
    current->next = &temp;
    current = current->next;
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
    curr = curr->next;
  }
  cout << endl;
}

bool List::makeEmpty() {
  Node* curr = head;
  Node* next = curr->next;
  while(curr != NULL) {
    delete curr;
    curr = next;
    next = curr->next;
  }

  head = NULL;
}

bool List::insert(int pos, Node* n) {
  Node* insertAfter = head;
  for(int i = 0; i < pos; i++) {
    if(insertAfter == NULL) {
      return false;
    }

    insertAfter = insertAfter->next;
  }

  Node* insertBefore = insertAfter->next;
  insertAfter->next = n;
  n->next = insertBefore;

  return true;
}

Node* List::find(int val) {
  Node* curr = head;
  while(curr!= NULL) {
    curr = curr->next;
    if(curr->val == val) {
      return curr;
    }
  }

  return NULL;
}

Node* List::remove(int val) {
  Node* curr = head;
  while(curr!= NULL) {
    curr = curr->next;
    if(curr->next->val == val) {
      curr->next = curr->next->next;
      return curr.next;
    }
  }

  return NULL;
}

Node* List::findAtIndex(int index) {
  Node* curr = head->next;
  if(curr == NULL) {
    return NULL;
  }

  for(int i = 0; i < index; i++) {
    curr = curr->next;
    if(curr == NULL) {
      return NULL;
    }
  }

  return curr;
}

Node* List::removeAtIndex(int index) {
  Node* curr = head;
  Node* next;

  for(int i = 0; i < index; i++) {
    curr = curr->next;
    if(curr == NULL) {
      return NULL;
    }
  }

  next = curr->next;
  if(next == NULL) {
    curr->next = NULL;
    delete next;
  } else {
    curr->next = next->next;
    delete next;
  }

  return next;
}
