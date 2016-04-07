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
    if (metrics <= path_length) {//если существу хватает длины хода, то премещаем его
        x0 = x;
        y0 = y;
        return true;
    }
    else {
        cout << "Too far. Creature`s path length = " << path_length << endl;
        return false;
    }

}

creature::creature() {
    path_length = 5;
    x0 = 0;
    y0 = 0;
}
