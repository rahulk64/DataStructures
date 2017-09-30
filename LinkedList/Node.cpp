#include "Node.hpp"

Node::Node(int v) {
  val = v;
  next = nullptr;
}

Node::Node(int v, Node* n) {
  val = v;
  next = n;
}

int Node::getValue() {
  return val;
}

void Node::setValue(int v) {
  val = v;
}

Node* Node::getNext() {
  return next;
}

void Node::setNext(Node* n) {
  next = n;
}
