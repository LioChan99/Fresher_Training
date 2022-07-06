#ifndef BAI2_H
#define BAI2_H
#include<iostream>
using namespace std;

template<class T,int n>
class Stack
{
    private:
      T array[n];
      int i=0;
    public:
      Stack(){};
      void Push(const T &x);
      T Pop();
      void Peek();
      bool isFull();
      bool isEmpty();

};
#endif