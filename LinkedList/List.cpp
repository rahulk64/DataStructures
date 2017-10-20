#include "List.hpp"
#include <cstddef>
#include <iostream>
using namespace std;

List::List() {
  head = nullptr;
}

List::~List() {
  makeEmpty();
  delete head;
}

List::List(int val) {
  Node* first = new Node(val);
  head = first;
}

List::List(int size, int arr[]) {
  if(size == 0) {
    head = nullptr;
  } else {
    Node* current = new Node(arr[0]);
    head = current;
    for(int i = 1; i < size; i++) {
      Node* temp = new Node(arr[i]);
      current->setNext(temp);
      current = current->getNext();
    }
  }
}

Node* List::getHead() {
  return head;
}

void List::setHead(Node* first) {
  head = first;
}

bool List::isEmpty() {
  if(head == NULL) {
    return true;
  } else {
    return false;
  }
}

void List::printList() {
  Node* curr = head;
  if(isEmpty()) {
    cout << "(Empty List)" << endl;
  } else {
    cout << "HEAD";
    while(curr !=NULL) {
      cout << "-> " << curr->getValue();
      curr = curr->getNext();
    }
    cout << endl;
  }
}

void List::makeEmpty() {
  Node* curr = head;
  Node* temp;
  while(curr != NULL) {
    temp = curr->getNext();
    delete curr;
    curr = temp;
  }

  head = NULL;
}

bool List::insert(int pos, Node* n) {
  pos--;
  if(pos < 0) {
    return false;
  }

  if(pos == 0) {
    n->setNext(head);
    head = n;

    return true;
  }

  Node* insertAfter = head;
  for(int i = 1; i < pos; i++) {
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

bool List::insert(int pos, int val) {
  pos--;

  if(pos < 0) {
    return false;
  }

  if(pos == 0) {
    Node* n = new Node(val);

    n->setNext(head);
    head = n;

    return true;
  }

  Node* insertAfter = head;

  for(int i = 1; i < pos; i++) {
    if(insertAfter == nullptr) {
      return false;
    }

    insertAfter = insertAfter->getNext();
  }

  Node* n = new Node(val);

  Node* insertBefore = insertAfter->getNext();
  insertAfter->setNext(n);
  n->setNext(insertBefore);

  return true;
}

bool List::insertBeginning(Node* n) {
  return insert(1, n);
}

bool List::insertBeginning(int val) {
  return insert(1, val);
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

  for(int i = 1; i < index; i++) {
    curr = curr->getNext();
    if(curr == nullptr) {
      return nullptr;
    }
  }

  return curr;
}

Node* List::findAtPosition(int pos) {
  return findAtIndex(pos-1);
}

Node* List::removeAtIndex(int index) {
  Node* curr = head;
  Node* next;
  Node* toReturn;

  if(index == 0) {
    next = curr->getNext();
    toReturn = next;
    delete curr;
    head = next;
    return toReturn;
  }

  for(int i = 1; i < index; i++) {
    curr = curr->getNext();
    if(curr == nullptr) {
      return nullptr;
    }
  }

  next = curr->getNext();
  toReturn = next;
  if(next == nullptr) {
    curr->setNext(nullptr);
    delete next;
  } else {
    curr->setNext(next->getNext());
    delete next;
  }

  return toReturn;
}

Node* List::removeAtPosition(int pos) {
  return removeAtIndex(pos-1);
}
