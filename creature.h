//
// Created by anton on 07.04.16.
//

#ifndef HMM_CREATURE_H
#define HMM_CREATURE_H

#include <iostream>
#include <cmath>

using namespace std;

class creature {
protected:
    unsigned int health;
    //количество очков здоровья
    unsigned int damage;
    //урон, наносимый существом
    unsigned int defense;
    //защита - то, сколько урона существо может предотвратить
    double path_length;
    //длина хода
    double x0;
    //абцисса координаты, на которой находится существо
    double y0;
    //ордината координаты, на которой находится существо
    bool alive;
    //живо существо(1) или нет(0)
    unsigned char belong_to;//принадлежность к 1 или 2 игроку
public:

    creature() {
        x0 = 2;
        y0 = 1;
    }

    virtual unsigned int get_damage(creature another) {
        if (defense < another.damage) {//если защита не полностью поглощает урон, то наносим урон
            unsigned int health_los = damage - defense;//потеря хп = дамаг - защита
            health = health - health_los;//уменьшаем здоровье в соответствии с нанесённым уроном
            return health_los;
        }
        else
            return 0;
    }

    virtual void attack(creature another) {

        if (another.alive) {
            another.get_damage(*this);
        }
    }

    virtual bool creature::move(double x, double y) {
        double metrics = abs(x0 - x) + abs(y0 - y);//вычисляем расстояние до точки с текущего положения существа

        bool answer;
        if (metrics <= path_length) {//если существу хватает длины хода, то премещаем его
            answer = true;

            if (map.empty(x, y)) {//если клетка не занята другим существом
                x0 = x;
                y0 = y;
            }
            else//если клетка занята другим существом, то остановиться на предыдущей клетке и атаковать противника
            {
                if (y - y0 == 0) {//если двигаемся строго горизонтально
                    if (x > x0)//если двигаемся направо
                        x0 = x - 1;
                    else//если двигаемся налево
                        x0 = x + 1;
                }
                else {
                    x0 = x;
                    if (y > y0)//если двигаемся наверх
                        y0 = y - 1;
                    else//если двигаемся вниз
                        y0 = y + 1;
                }

                attack(map.get_creature(x, y));

            }
        } else {//если недостаточно длины хода
            cout << "Too far. Creature`s path length = " << path_length << endl;
            answer = false;
        }
        return answer;
    }
};


#endif //HMM_CREATURE_H
