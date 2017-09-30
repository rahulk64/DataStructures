#include "List.hpp"
#include <cstddef>
#include <iostream>
using namespace std;

List::List() {
  head = nullptr;
}

List::List(int val) {
  Node first(val);
  head = &first;
}

List::List(int num, int arr[]) {
  if(num == 0) {
    head = nullptr;
    return;
  }

  Node current(arr[0]);
  for(int i = 1; i < num; i++) {
    Node temp(arr[i]);
    current.setNext(&temp);
    current = *(current.getNext());
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
  if(curr == nullptr) {
    cout << "Empty List" << endl;
    return;
  }

  while(curr !=nullptr) {
    cout << curr->getValue() << ", ";
    curr = curr->getNext();
  }
  cout << endl;
}

bool List::makeEmpty() {
  Node* curr = head;
  Node* next = curr->getNext();
  while(curr != nullptr) {
    delete curr;
    curr = next;
    next = curr->getNext();
  }

  head = nullptr;
}

bool List::insert(int pos, Node* n) {
  Node* insertAfter = head;
  for(int i = 0; i < pos; i++) {
    if(insertAfter == nullptr) {
      return false;
    }

    insertAfter = insertAfter->getNext();
  }

  Node* insertBefore = insertAfter->getNext();
  insertAfter->setNext(n);
  n->setNext(insertBefore);

  return true;
}

Node* List::find(int val) {
  Node* curr = head;
  while(curr!= nullptr) {
    curr = curr->getNext();
    if(curr->getValue() == val) {
      return curr;
    }
  }

  return nullptr;
}

Node* List::remove(int val) {
  Node* curr = head;
  while(curr!= nullptr) {
    curr = curr->getNext();
    if(curr->getNext()->getValue() == val) {
      curr->setNext(curr->getNext()->getNext());
      return curr->getNext();
    }
  }

  return nullptr;
}

Node* List::findAtIndex(int index) {
  Node* curr = head->getNext();
  if(curr == nullptr) {
    return nullptr;
  }

  for(int i = 0; i < index; i++) {
    curr = curr->getNext();
    if(curr == nullptr) {
      return nullptr;
    }
  }

  return curr;
}

Node* List::removeAtIndex(int index) {
  Node* curr = head;
  Node* next;

  for(int i = 0; i < index; i++) {
    curr = curr->getNext();
    if(curr == nullptr) {
      return nullptr;
    }
  }

  next = curr->getNext();
  if(next == nullptr) {
    curr->setNext(nullptr);
    delete next;
  } else {
    curr->setNext(next->getNext());
    delete next;
  }

  return next;
}
