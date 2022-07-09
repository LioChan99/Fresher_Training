#ifndef CONTROL_H
#define CONTROL_H
#include "Player.h"
#include "Monster.h"
#include<string.h>
#include <cstdlib>
#include <ctime>
#include <vector>
Monster medusa("Medusa",10,3,rand() % 75+26,"fire");
    Monster dracula("Dracula",4,2,rand()%15+11,"sand");
    Monster frankenstein("Frankenstein",1,1,rand()%10+1,"water");
    Monster athena("Athena",1,1,10,"wizardry");
class Control 
{
private:
    Player player;
    Monster medusa;
    Monster dracula;
    Monster frankenstein;
    Monster athena;
public:
    void addPlayer();
    Monster ramdomMonster();
    void playGame();  
};
#endif