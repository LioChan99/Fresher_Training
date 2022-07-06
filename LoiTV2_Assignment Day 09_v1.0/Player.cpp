#include "Player.h"
Player::Player()
{
    this-> setName("Loi");
    this-> setShortName('L');
    this-> setHealth(10);
    this-> setDamage(1);
    this-> setGold(0);
    this-> level = 1;  
}
int Player::getLevel()
{
    return this->level;
}
void Player::setLevel(int level)
{
    this->level = level;
}
void Player::showFail()
{
    cout<<"You Failed!"<<endl;
    cout<<"Your Level: "<< level<<endl;
    cout<<"Your Gold: "<< getGold()<<endl;
}
void Player::showWin()
{
    cout<<"You Win!"<<endl;
    cout<<"Your Gold: "<< getGold()<<endl;  
}