#ifndef MONSTER_H
#define MONSTER_H
#include "MyGame.h"
class Monster : public MyGame
{
    private:
       string type;
    public:
       Monster(const string &name, const int &health, const int &damage, const int &gold,const string &type );
       string getType();
       void setType(string type);
};
#endif