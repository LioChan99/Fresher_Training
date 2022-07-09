
#include "Player.h"
#include "Monster.h"
#include<string.h>
#include <cstdlib>
#include <ctime>
#include <vector>

//Player player;
Monster medusa("Medusa",10,3,rand() % 75+26,"fire");
Monster dracula("Dracula",4,2,rand()%15+11,"sand");
Monster frankenstein("Frankenstein",1,1,rand()%10+1,"water");
Monster athena("Athena",1,1,10,"wizardry");
//Monster 
vector<Player> v_player;
void addPlayer(Player &player)
{ 
   player.setInfor();
   v_player.push_back(player);
}
Monster randomMonster()
    { 
      srand(time(NULL));
      int num = rand() % 4;
         switch (num)
         {
            case 0:
            {
               return medusa;
            }
            case 1:
            {
               return dracula;
            }
            case 2:
            {
               return frankenstein;
            }
            case 3:
            {
               return athena;
            }
         }
    }

int main()
{  
   Player player;
   addPlayer(player);
   system("cls");
   while(player.getHealth()>0 && player.getLevel()<20)
   {  
      int choose;
      cout<<"                       Your status: "<<endl;
      cout<<player.getName()<<"\tLevel: "<<player.getLevel()<<"\tHealth: "<<player.getHealth()<<"\tGold: "<<player.getGold()<<"\tDamage: "<<player.getDamage()<<endl;
      cout<<endl;
      cout<<"  Alert!: New Monster is comming!!!"<<endl;
      cout<<"Press 1 : Run away"<<"\tPress2: Fight"<<endl;
   
      cin>>choose;
      switch(choose)
      {
        case 1:
        { 
            system("cls");
            if((rand() % 2)==0)
            { 
               cout<<"You successfully escaped!"<<endl;
            }
            else
            {  
               system("cls");
               Monster X = randomMonster();
               cout<<"You got damaged -"<<X.getDamage()<<" by "<<X.getName()<<endl;
               //cout<<randomMonster().getDamage()<<endl;
               player.setHealth(player.getHealth()- X.getDamage());
            }
         break;
        }
        case 2:
         {  
            system("cls");
            medusa.setHealth(15);
            dracula.setHealth(4);
            frankenstein.setHealth(1);
            Monster X= randomMonster();
            if (X.getName()=="Athena")
            {
               cout<<"You got help from Athena: Health +2, Gold +10"<<endl;
               player.setGold(player.getGold()+X.getGold());
               player.setHealth(player.getHealth()+2);
            }

            else
            {
               cout<<"You encourter "<<X.getName()<<endl;
            //cout<<player.getHealth()<< " "<<X.getHealth()<<endl;
               while(X.getHealth()>0 && player.getHealth()>0)
               {
                  X.setHealth(X.getHealth()-player.getDamage());
                  player.setHealth(player.getHealth()- X.getDamage());
               }
            //cout<<player.getHealth()<< " "<<X.getHealth()<<endl;
               if(player.getHealth()<=0)
               {  cout<<endl;
                  player.showFail();
                  return 0;
               }
               else if (player.getHealth()>=0)
               {   
                  if(X.getName()=="Medusa")
                  {
                     cout<<"You defeated the Monster!: "<<"Gold + "<<X.getGold()<<", other properties +2"<<endl;
                     player.setDamage(player.getDamage()+2);
                     player.setGold(player.getGold()+X.getGold());
                     player.setHealth(player.getHealth()+2);
                     player.setLevel(player.getLevel()+2);
                  }
               
                  else
                  {
                     cout<<"You defeated the Monster!: "<<"Gold + "<<X.getGold()<<", other properties +1"<<endl;
                     player.setDamage(player.getDamage()+1);
                     player.setGold(player.getGold()+X.getGold());
                     player.setHealth(player.getHealth()+1);
                     player.setLevel(player.getLevel()+1);
                  }
                break;
               }
            }
         }
         default:
         break;
      }
      if (player.getLevel()==20)
      {  cout<<endl;
         player.showWin();
         return 0;
      }
   }
}
