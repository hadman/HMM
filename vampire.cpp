//
// Created by anton on 08.04.16.
//

#include "vampire.h"

void vampire::attack(creature another) {
    if (another.alive) {
        unsigned int regeneration = another.get_damage(*this);
        health += regeneration;
    }
}

vampire::vampire() {
    health = 5;
}
