//
// Created by anton on 07.04.16.
//

#include "creature.h"

#include <iostream>
#include <cmath>

using namespace std;

void creature::attack(creature another) {

    if (another.alive) {
        another.get_damage(*this);
    }
}

unsigned int creature::get_damage(creature another) {
    if (defense < another.damage) {//если защита не полностью поглощает урон, то наносим урон
        unsigned int health_los = damage - defense;//потеря хп = дамаг - защита
        health = health - health_los;//уменьшаем здоровье в соответствии с нанесённым уроном
        return health_los;
    }
    else
        return 0;
}

bool creature::move(double x, double y) {
    double metrics = abs(x0 - x) + abs(y0 - y);//вычисляем расстояние до точки с текущего положения существа
    cout << metrics << endl;
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
