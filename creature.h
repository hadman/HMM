//
// Created by anton on 07.04.16.
//
//данный класс отвечает за взаимодействие существ на поле боя
#ifndef HMM_CREATURE_H
#define HMM_CREATURE_H

#include <iostream>
#include <cmath>
#include "map.h"

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
    int belong_to;
    //принадлежность к 1 или 2 игроку
    int count_hp; // сколько здоровья вылечивает
    int arrow_damage;//урон, наносимый стрелком, у остальных будет равен 0
public:
    friend class player;

    friend class undead;

    friend class doctor;

    friend class warrior;

    friend class vampire;

    friend class skeleton_archer;

    friend class map;

    friend class the_game;

    virtual int get_damage(creature &another) {
        if (defense < another.damage) {//если защита не полностью поглощает урон, то наносим урон
            int health_los = another.damage - defense;//потеря хп = дамаг - защита
            health = health - health_los;//уменьшаем здоровье в соответствии с нанесённым уроном
            cout << ID << " lose " << health_los << " hp" << endl;
            if (health <= 0) {//если существо умерло
                alive = false;
                map::del_from_map(*this);
            }
            return health_los; // возвращаем для вампира
        }
        else
            return 0;
    }

    virtual bool add_hp(creature &another); // Восстановление здоровья персонажа. по умолчанию существо не лечит


    unsigned int get_id() {
        return ID;
    }

    void move(int new_x, int new_y) // перемещает персонажа в указанную клетку
    {
        map::map_of_id[x0][y0] = 0; // удалили из прошлой клетки
        map::map_of_id[new_x][new_y] = ID;     // преместили в новую клетку
        x0 = new_x;
        y0 = new_y;
    }

    bool attack(creature *attacked_creature) {
        attacked_creature->get_damage(*this);

    }
};


#endif //HMM_CREATURE_H
