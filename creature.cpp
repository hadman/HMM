//
// Created by anton on 07.04.16.
//

#include "creature.h"
#include <math.h>

virtual void creature::attack(creature another) {

    if (another.alive) {
        another.get_damage(*this);
    }
}

virtual unsigned int creature::get_damage(creature another) {
    if (defense < another.damage) {//если защита не полностью поглощает урон, то наносим урон
        unsigned int health_los = damage - defense;//потеря хп = дамаг - защита
        health = health - health_los;//уменьшаем здоровье в соответствии с нанесённым уроном
        return health_los;
    }
    else
        return 0;
}

virtual bool creature::move(unsigned int x, unsigned int y) {
    unsigned int metrics = sqrt(pow(x - x0, 2) + pow(y - y0, 2));
    if (
}
