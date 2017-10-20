#include "StackArray.hpp"
#include <iostream>
#include <assert.h>
using namespace std;

StackArray::StackArray() {
  stackTopIndex = 0;
}

StackArray::StackArray(int num) {
  stackTopIndex = 1;
  array.push_back(num);
}

StackArray::StackArray(int size, int arr[]) {
  for(int i = 0; i < size; i++) {
    array.push_back(arr[i]);
  }
}

bool StackArray::isEmpty() {
  return array.empty();
}

void StackArray::printStack() {
  if(isEmpty()) {
    cout << "(empty stack)" << endl;
  } else {
    cout << "Bottom-> " << array.at(0);
    for(int i = 1; i < array.size(); i++) {
      cout << ", " << array.at(i);
    }
    cout << " <-Top" << endl;
  }
}

bool StackArray::push(int item) {
  array.push_back(item);
}

int StackArray::getStackSize() {
  return array.size();
}

int StackArray::pop() {
  int returnVal = array.at(getStackTopIndex());
  array.pop_back();
  return returnVal;
}

int StackArray::peek() {
  return array.at(getStackSize()-1);
}

int StackArray::getStackTopIndex() {
  return array.size()-1;
}
