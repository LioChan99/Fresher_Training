#ifndef BAI1_H
#define BAI1_H
#include<iostream>
using namespace  std;
template<class T, class U>

class Pair
{
   private:
      T first;
      U second;
    public:
      Pair(T first, U second);
      T getFirst() const ;
      U getSecond() const ;

};
#endif