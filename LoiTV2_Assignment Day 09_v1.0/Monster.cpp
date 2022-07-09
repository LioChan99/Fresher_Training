#include "Monster.h"
Monster:: Monster(const string &name, const int &health, const int &damage, const int &gold,const string &type ): MyGame(name, health, damage, gold)
{
    this->type = type;
}
string Monster::getType()
{
    return type;
}
void Monster:: setType(string type)
{
    this->type= type;
}