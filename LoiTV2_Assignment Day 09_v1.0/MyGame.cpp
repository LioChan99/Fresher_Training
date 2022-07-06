#include "MyGame.h"
MyGame::MyGame(const string name,const char shortName,const int health,const int damage,const int gold){
    this-> name = name;
    this-> shortName = shortName;
    this-> health = health;
    this-> damage = damage;
    this-> gold = gold;
}
MyGame::MyGame(){};
string MyGame::getName()
{
    return this->name;
}
void MyGame::setName(const string &name)
{
    this-> name = name;
}
char MyGame::getShortName()
{
    return this->shortName;
}
void MyGame::setShortName(const char &shortName)
{
    this->shortName= shortName;
}
short int MyGame::getHealth()
{
    return this->health;
}
void MyGame::setHealth(const int &health)
{
    this->health= health;
}
short int MyGame::getDamage()
{
    return this->damage;
}
void MyGame::setDamage(const int &damage)
{   if(1 <= damage <= 4)
    {
       this->damage= damage;
    }
}
short int MyGame::getGold()
{
    return this->gold;
}
void MyGame::setGold(const int &gold)
{
    this->gold= gold;
}
