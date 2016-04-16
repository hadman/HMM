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
    //creature **creatureMass;            // массив указателей на его персонажей
    vector<creature *> creatureMass;
    int creatureCount;                  // кол-во персонажей
    int playerNum;                      // номер игорока
public:
    friend class map;

    friend class the_game;

    player(int Num) {
        playerNum = Num;
        creatureCount = 0;
    }

    bool addCreature(creature *addCr) // добавление персонажа игроку
    {
        if (addCr->alive == true) {


//            creature **tmp = new creature *[creatureCount];
//            for (int i = 0; i < creatureCount; ++i) {
//                tmp[i] = creatureMass[i];
//            }
//            delete[] creatureMass;
//            creatureMass = new creature *[creatureCount + 1];
//            for (int i = 0; i < creatureCount; ++i) {
//                creatureMass[i] = tmp[i];
//            }
//            creatureMass[creatureCount] = addCr;


            creatureMass.push_back(addCr);
            creatureCount++;
            //delete[] tmp;



            if (playerNum == 1) {
                addCr->belong_to = 1;
                //cout << "smth add to first player" << endl;
            } else {
                addCr->belong_to = 2;
                //cout << "smth add to second player" << endl;
            }
            return true;
        } else {
            return false;
        }
    }

    bool delCreature(creature *addCr) // ищем персонажа по id и удаляем
    {
        for (int i = 0; i < creatureCount; ++i) {
            if (creatureMass[i]->get_id() == addCr->get_id()) {
                creatureMass.erase(creatureMass.begin() + i);
                return true;
            }
        }
        return false;
    }

    bool input_position(int &inp_x, int &inp_y) {
        int x;
        int y;
        cout << "X = ";
        cin >> x;
        cout << "Y = ";
        cin >> y;
        inp_x = x;
        inp_y = y;
    };


    int count_of_creatures() {
        int i = 0;
        for (int j = 0; j < creatureCount; ++j) {
            if (creatureMass[j]->alive == true) {
                i++;
            }
        }
        return i;
    }

    bool is_this_creature_of_this_player(unsigned int creature_id) // проверяет, есть ли персонаж с таким номер у игрока
    {
        for (int i = 0; i < creatureCount; ++i) {
            if (creatureMass[i]->get_id() == creature_id) {
                return true;
            }
        }
        return false;
    }

    creature *return_creature_with_this_id(unsigned int creature_id) // возвращает персонажа по id
    {
        for (int i = 0; i < creatureCount; ++i) {
            if (creatureMass[i]->get_id() == creature_id) {
                return creatureMass[i];
            }
        }
    }

    void put_creatures_on_map(map &MAP) {
        if (playerNum == 1) // расстановка существ первого игрока на карте
        {
            int x = 0; // координата по высоте
            int y = 0; // координата по ширине
            int i = 0; // счетчик

            while (i < creatureCount) // расставляем персонажей на карте. начиная слева сверху
            {
                MAP.map_of_id[x][y] = creatureMass[i]->get_id();
                creatureMass[i]->x0 = x;
                creatureMass[i]->y0 = y;

                i++;
                x = (x + 1) % MAP.height;
                if (x == 0) {
                    y++;
                }
            }
        }
        else // расстановка существ второго игрока на карте
        {
            int x = 0; // координата по высоте
            int y = MAP.width - 1; // координата по ширине
            int i = 0; // счетчик

            while (i < creatureCount) // расставляем персонажей на карте. начиная слева сверху
            {
                MAP.map_of_id[x][y] = creatureMass[i]->get_id();
                creatureMass[i]->x0 = x;
                creatureMass[i]->y0 = y;
                i++;
                x = (x + 1) % MAP.height;
                if (x == 0) {
                    y--;
                }
            }
        }
    }


};

#endif //HMM_PLAYER_H
