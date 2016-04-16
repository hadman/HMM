//
// Created by anton on 07.04.16.
//

#ifndef HMM_CREATURE_H
#define HMM_CREATURE_H

#include <iostream>
#include <cmath>
//#include "map.h"
//#include "player.h"

using namespace std;

//todo-anton написать самописный модуль, если потребуется

class creature {
protected:
    unsigned int ID;
    // уникальный номе персонажа
    int health;
    //количество очков здоровья
    unsigned int damage;
    //урон, наносимый существом
    unsigned int defense;
    //защита - то, сколько урона существо может предотвратить
    unsigned int path_length;
    //длина хода
    int x0;
    //абцисса координаты, на которой находится существо
    int y0;
    //ордината координаты, на которой находится существо
    bool alive;
    //живо существо(1) или нет(0)
    int belong_to;//принадлежность к 1 или 2 игроку
public:
    friend class player;

    friend class undead;

    friend class doctor;

    friend class warrior;

    friend class vampire;

    friend class skeleton_archer;

    friend class map;

    friend class the_game;

    creature() {

    }


    virtual int get_damage(creature &another) {
        if (defense < another.damage) {//если защита не полностью поглощает урон, то наносим урон
            int health_los = another.damage - defense;//потеря хп = дамаг - защита
            health = health - health_los;//уменьшаем здоровье в соответствии с нанесённым уроном
            cout << ID << " lose " << health_los << " hp" << endl;
            if (health <= 0) {
                alive = false;
            }
            return health_los; // возвращаем для вампира
        }
        else
            return 0;
    }

    virtual bool attack(creature &another) {  // возможность атаковать. по умолчанию существо не атакует
        return false;
    }

    virtual bool attack_arrow(creature &another) // стрельба из лука. по умолчанию существо не струляет из лука
    {
        return false;
    }

    virtual bool add_hp(creature &another) // Восстановление здоровья персонажа. по умолчанию существо не лечит
    {
        return false;
    }

    unsigned int get_id() {
        return ID;
    }

    int get_x0() {
        return x0;
    }

    int get_y0() {
        return y0;
    }

    double distance_to_point(int x, int y) // возвращает расстояние от точки (x,y) до персонажа
    {
        return sqrt(abs(x - x0) + abs(y - y0));
    }


    virtual bool move(int x, int y) // ничего не проверяет. просто переносит персонажа в нужную координату
    {
        x0 = x;
        y0 = y;
//        int metrics = abs(x0 - x) + abs(y0 - y);//вычисляем расстояние до точки с текущего положения существа
//
//        bool answer;
//        if (metrics <= path_length) {//если существу хватает длины хода, то премещаем его
//            answer = true;
//
//            if (true) {//если клетка не занята другим существом // MAP.get_creature_ID(x, y)
//                x0 = x;
//                y0 = y;
//            }
//            else//если клетка занята другим существом, то остановиться на предыдущей клетке и атаковать противника
//            {
//                if (y - y0 == 0) {//если двигаемся строго горизонтально
//                    if (x > x0)//если двигаемся направо
//                        x0 = x - 1;
//                    else//если двигаемся налево
//                        x0 = x + 1;
//                }
//                else {
//                    x0 = x;
//                    if (y > y0)//если двигаемся наверх
//                        y0 = y - 1;
//                    else//если двигаемся вниз
//                        y0 = y + 1;
//                }
//
//                //attack(map::get_creature(x, y));
//
//            }
//        } else {//если недостаточно длины хода
//            cout << "Too far. Creature`s path length = " << path_length << endl;
//            answer = false;
//        }
//        return answer;
    }

};


#endif //HMM_CREATURE_H
