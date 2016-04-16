//
// Created by anton on 07.04.16.
//
//данный класс отвечает за взаимодействие существ на поле боя
#ifndef HMM_CREATURE_H
#define HMM_CREATURE_H

#include <iostream>
#include <cmath>
//#include "map.h"


using namespace std;

//todo-anton написать самописный модуль, если потребуется

class creature {
protected:
    unsigned int ID;
    // уникальный номе персонажа
    int start_hp;
    // начальное кол-во здоровья
    int health;
    //количество очков здоровья
    int defense;
    //защита - то, сколько урона существо может предотвратить
    int path_length;
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
    int damage;
public:
    friend class player;

    friend class undead;

    friend class doctor;

    friend class warrior;

    friend class archer;

    friend class vampire;

    friend class skeleton_archer;

    friend class map;

    friend class the_game;


    virtual int get_damage(int enemy_damage, map &MAP) {
        // int hit = arrow_damage > damage ? arrow_damage : damage;//выбираем наибольший урон из возможных

        if (defense < enemy_damage) {//если защита не полностью поглощает урон, то наносим урон
            int health_los = enemy_damage - defense;//потеря хп = дамаг - защита
            health = health - health_los;//уменьшаем здоровье в соответствии с нанесённым уроном
            cout << ID << " lose " << health_los << " hp" << endl;

            if (health <= 0) {//если существо умерло
                alive = false;
                MAP.wipe_from_map(x0, y0);
            }

            return health_los; // возвращаем для вампира
        }
        else
            return 0;
    }

    virtual bool add_hp(creature *another) // Восстановление здоровья персонажа. по умолчанию существо не лечит
    {
        return false;
    }

    unsigned int get_id() {
        return ID;
    }

    void move(int new_x, int new_y, map &MAP) // перемещает персонажа в указанную клетку
    {
        MAP.map_of_id[x0][y0] = 0; // удалили из прошлой клетки
        MAP.map_of_id[new_x][new_y] = ID;     // преместили в новую клетку
        x0 = new_x;
        y0 = new_y;
    }

    virtual bool arrow_attack(creature *attacked_creature, map &MAP) // по умолчанию существо не стреляет
    {
        return false;
    }

    virtual bool attack(creature *attacked_creature, map &MAP) { // по умолчанию существо не атакует
        return false;
    }

    bool can_creature_move_to_point(int x,
                                    int y) // проверяет находится ли заданная координата в зоне досягаемости хода персонажа
    {
        if ((abs(this->x0 - x) >= this->path_length) || (abs(this->y0 - y) >= this->path_length)) {
            return false;
        }
        return true;
    }

    double distance_to_point(int x, int y) // возвращает расстояние от точки (x,y) до персонажа
    {
        return sqrt(abs(x - this->x0) + abs(y - this->y0));
    }

};


#endif //HMM_CREATURE_H
