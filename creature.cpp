//
// Created by anton on 07.04.16.
//

#include "creature.h"

virtual void creature::attack(creature another) {
//todo добавить ещё фич
    if (another.alive) {
        another.get_damage(*this);
    }
}

virtual bool creature::get_damage(creature another) {
    if (defense < another.damage) {//если защита не полностью поглощает урон, то наносим урон
        unsigned int health_los = damage - defense;//потеря хп = дамаг - защита
        health = health - health_los;//уменьшаем здоровье в соответствии с нанесённым уроном
    }
}
