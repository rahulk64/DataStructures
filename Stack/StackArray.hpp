#ifndef STACKARRAY
#define STACKARRAY
using namespace std;

#include<vector>

class StackArray {
public:
  StackArray();
  StackArray(int num);
  StackArray(int size, int arr[]);

  bool isEmpty();
  bool push(int item);
  int getStackSize();
  int pop();
  int peek();
  int getStackTopIndex();

private:
  int stackTopIndex;
  vector<int> array;
};

#endif
