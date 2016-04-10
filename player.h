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

private:
    std::vector<creature> creatureMass; // его персонажи
    int creatureCount;                  // кол-во персонажей
    int playerNum;                      // номер игорока
public:
    //friend class creature;
    player(int Num) {
        playerNum = Num;
        creatureCount = 0;
    }

    bool addCreature(creature addCr) // добавление персонажа игроку
    {
        if (addCr.alive == true) {
            creatureMass.push_back(addCr);
            creatureCount++;
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
