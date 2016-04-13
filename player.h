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
//        bool tmp;
//        int x = -1;
//        int y = -1;
//        cout << "Do  you want to do a motion? 0 - don't want; Else - want; ";
//        cin >> tmp;
//        if (tmp == 0) {
//            mas[0] = x;
//            mas[1] = y;
//            return 0;
//        } else {
////            while(!(cin >> x) || cin.get() != '\n')
////            {
////                cin.clear();
////                while(cin.get() != '\n');
////                cout << "Please input X>0" << endl;
////            }
////            //cout << "Please input Y>0 ";
////            while(!(cin >> y))
////            {
////                cin.clear();
////                while(cin.get() != '\n');
////                cout << "Please input Y>0" << endl;
////            }
//            cout << "x = ";
//            cin >> x;
//            cout << "y = ";
//            cin >> y;
//            mas[0] = x;
//            mas[1] = y;
//            return 1;
    };



    int count_of_creatures() {
        return creatureCount;
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
};

#endif //HMM_PLAYER_H
