#ifndef MYGAME_H
#define MYGAME_H
#include<iostream>
using namespace std;
class MyGame
{
    private:
      string name;
      char shortName;
      int health;
      int damage;
      int gold;
    public:
      MyGame(const string name, const char shortName, const int health, const int damage, const int gold);
      MyGame();
      string getName();
      void setName(const string &name);
      char getShortName();
      void setShortName(const char &shortName);
      short int  getHealth();
      void setHealth(const  int &health);
      short int getDamage();
      void setDamage(const  int &damage);
      short int getGold();
      void setGold(const  int &gold);
};
#endif
