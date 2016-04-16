//
// Created by anton on 08.04.16.
//

#ifndef HMM_UNDEAD_H
#define HMM_UNDEAD_H

#include "creature.h"

#include <iostream>

using namespace std;

class undead : public virtual creature { // виртуальное наследование для решения проблемы ромбовидного наследования
protected:
    unsigned int death_aura;//после убийства нежити, противнику наносится урон, равный death aura
public:

    virtual unsigned int get_damage(creature another) {
        if (defense < another.damage) {//если защита не полностью поглощает урон, то наносим урон
            unsigned int health_los = damage - defense;//потеря хп = дамаг - защита
            health -= health_los;//уменьшаем здоровье в соответствии с нанесённым уроном

            if (health <= 0) {//если существо убили, то атакуем пртоивника аурой смерти
                another.health -= death_aura;
                alive = 0;
            }

            return health_los;
        }
        else
            return 0;
    }

    };


#endif //HMM_UNDEAD_H
