//
// Created by anton on 08.04.16.
//

#ifndef HMM_UNDEAD_H
#define HMM_UNDEAD_H


#include <iostream>

using namespace std;

class undead : public virtual creature { // виртуальное наследование для решения проблемы ромбовидного наследования
protected:
    int damage;
    unsigned int death_aura;//после убийства нежити, противнику наносится урон, равный death aura
public:

    friend class vampire;

    friend class skeleton_archer;

    virtual int get_damage(int enemy_damage, map &MAP) {
//        int hit = arrow_damage > damage ? arrow_damage : damage;//выбираем наибольший урон из возможных

        if (defense < enemy_damage) {//если защита не полностью поглощает урон, то наносим урон
            int health_los = enemy_damage - defense;//потеря хп = дамаг - защита
            health = health - health_los;//уменьшаем здоровье в соответствии с нанесённым уроном
            cout << ID << " lose " << health_los << " hp" << endl;

            if (health <= 0) {//если существо умерло
                alive = false;
                MAP.wipe_from_map(x0, y0);
//                if (another->distance_to_point(x0, y0) == 1)
//                    another->health -= death_aura;
            }

            return health_los; // возвращаем для вампира
        }
        else
            return 0;
    }

    };


#endif //HMM_UNDEAD_H
