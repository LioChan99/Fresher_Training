#ifndef CONTROL_H
#define CONTROL_H
#include "Player.h"
#include "Monster.h"

Player player;
Monster dragon("dragon",'d',20,4,0,"dragon");
Monster orc("orc",'o',4,2,0,"orc");
Monster slime("slime",'s',1,1,0,"slime");
int setDgold()
{
    int range = 100 - 26 + 1;
    return (rand() % range + 26);

}
int setOgold()
{
    int range = 25 - 11 + 1;
    return rand() % range + 11;
}
int setSgold()
{
    int range = 25 - 11 + 1;
    return rand() % range + 11;

}
int ramdom123()
{
   int range=3;
   return (rand()% range +1);
}
Monster randomMonster()
    {
      int num = rand() % 3+1;
         switch (num)
         {
            case 1:
            {
               return dragon;
               break;
            }
            case 2:
            {
               return orc;
               break;
            }
            case 3:
            {
               return slime;
               break;
            }
         }
    }

int main()
{   
   dragon.setGold(setDgold());
   orc.setGold(setOgold());
   slime.setGold(setSgold());
   cout<<dragon.getGold()<<" "<<orc.getGold()<<slime.getGold()<<endl;
   while(player.getHealth()>0 && player.getLevel()<20)
    {  int choose;
       cout<<"Press 1 if you choose escape"<<endl;
       cout<<"Press 2 if you choose fight"<<endl;
       cin>>choose;
       switch(choose)
       {
        case 1:
        {
          if((rand() % 2)==0)
          { 
            cout<<"You successfully escaped!"<<endl;
          }
          else
          {  cout<<"You got damaged!"<<endl;
             cout<<randomMonster().getDamage()<<endl;
             player.setHealth(player.getHealth()- randomMonster().getDamage());
          }
          break;
        }
        case 2:
         {  
            dragon.setHealth(20);
            orc.setHealth(4);
            slime.setHealth(1);
            Monster X= randomMonster();
            //cout<<player.getHealth()<< " "<<X.getHealth()<<endl;
            while(X.getHealth()>0 && player.getHealth()>0)
            {
               X.setHealth(X.getHealth()-player.getDamage());
               player.setHealth(player.getHealth()- X.getDamage());
            }
            //cout<<player.getHealth()<< " "<<X.getHealth()<<endl;
            if(player.getHealth()<=0)
            {  
               player.showFail();
               return 0;
            }
            else if (player.getHealth()>=0)
            {   
                cout<<"You defeated the Monster!"<<endl;
                player.setDamage(player.getDamage()+1);
                player.setGold(player.getGold()+X.getGold());
                player.setHealth(player.getHealth()+1);
                player.setLevel(player.getLevel()+1);
            }
            break;
         }
       }
    }
    if (player.getLevel()==20)
    {
      player.showWin();
      return 0;
    }

}
#endif