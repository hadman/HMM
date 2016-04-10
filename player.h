//
// Created by musta on 09.04.2016.
//

#ifndef HMM_PLAYER_H
#define HMM_PLAYER_H

#include "creature.h"
#include <vector>
#include <iostream>

using namespace std;

class player // хранит в себе всех своих персонажей и их кол-во
{

protected:
    creature **creatureMass;            // массив указателей на его персонажей
    int creatureCount;                  // кол-во персонажей
    int playerNum;                      // номер игорока
public:
    friend class map;
    player(int Num) {
        playerNum = Num;
        creatureCount = 0;
    }

    bool addCreature(creature *addCr) // добавление персонажа игроку
    {
        if (addCr->alive == true) {


            creature **tmp = new creature *[creatureCount];
            for (int i = 0; i < creatureCount; ++i) {
                tmp[i] = creatureMass[i];
            }
            delete[] creatureMass;
            creatureMass = new creature *[creatureCount + 1];
            for (int i = 0; i < creatureCount; ++i) {
                creatureMass[i] = tmp[i];
            }
            creatureMass[creatureCount] = addCr;
            //addCr->y0 = 1488;
            creatureCount++;
            //delete[] tmp;


            //creatureMass.push_back(addCr);

            if (playerNum == 1) {
                cout << "smth add to first player" << endl;
            } else {
                cout << "smth add to second player" << endl;
            }
            return true;
        } else {
            return false;
        }
    }
};

#endif //HMM_PLAYER_H
