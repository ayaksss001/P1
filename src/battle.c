#include <stdio.h>
#include <stdbool.h>
#include <time.h>
#include <stdlib.h>
#include "name.h"

int battle()   
{   
    name();
    int HERO_HP = 3;
    int SLIME_HP = 3;
    int hero_atk = -1;
    int slime_atk = -1;
    int BANK;
    bool check_play_box = true;
    char play_button;
    char attack_button;
    int c;

    
    
    
    while (play_button != 'q')
    {
        printf("Press [P]lay to play a game or [Q]uit for quit!\n");
        play_button = getchar();
        if(play_button == 'p' || play_button == 'P')
        {
            int slime_hp = SLIME_HP; 
            int hero_hp = HERO_HP;
            srand(time(NULL));
            int gold = rand() % 4 + 3;

            printf("Slime is attacking you! Press [K] to attack him! Slime hp = %d\n", slime_hp);
            
            while(hero_hp > 0)
            {   

                getchar();
                attack_button = getchar();

                if(attack_button == 'k' || attack_button == 'K' && slime_hp > 0)
                {
                    slime_hp += hero_atk;
                    
                    if (slime_hp > 0)
                    {
                        printf("You attacked slime! Slime hp = %d\n", slime_hp);
                        printf("Slime is not dead press [K] to attack him again!\n");
                    }
                    else
                    {   
                        while((c = getchar()) != '\n' && c != EOF){}
                        printf("Slime is dead!\nYou got %d coins! You have : %d coins\n", gold, BANK += gold, BANK);
                        
                        break;
                    }
                   
                }
                else
                {
                    hero_hp += slime_atk;
                    if(hero_hp > 0)
                    {
                        printf("Slime attacked you!Your hp = %d\nPress [K] to attack him back!\n", hero_hp);
                    }
                    else
                    {
                        while((c = getchar()) != '\n' && c != EOF){}
                        printf("You are dead!\n");
                        break;
                    }
                }
            }
        }else
        {
           while((c = getchar()) != '\n' && c != EOF){}         
        }

    }
    return  0;
}