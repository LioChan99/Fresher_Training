#ifndef PLAYER_H
#define PLAYER_H
#include "MyGame.h"
#include<string>
class Player : public MyGame
{
    private:
      short level;
    public:
       Player();
       int getLevel();
       void setLevel(int level);
       void setInfor();
       void showFail();
       void showWin();

};
#endif