#ifndef MYGAME_H
#define MYGAME_H
#include<iostream>
using namespace std;
class MyGame
{
    private:
      string name;
      int health;
      int damage;
      int gold;
    public:
      MyGame(const string name, const int health, const int damage, const int gold);
      MyGame();
      string getName();
      short int  getHealth();
      void setHealth(const  int &health);
      short int getDamage();
      void setName(const string &name);
      void setDamage(const  int &damage);
      short int getGold();
      void setGold(const  int &gold);
};
#endif
