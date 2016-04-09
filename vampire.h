//
// Created by anton on 08.04.16.
//

#ifndef HMM_VAMPIRE_H
#define HMM_VAMPIRE_H

#include "undead.h"

class vampire : public undead {
public:
    friend class creature;

    virtual void attack(creature another) {
        if (another.alive) {
            unsigned int regeneration = another.get_damage(*this);
            health += regeneration;
        }
    }


    vampire() {
        health = 5;
        x0 = 0;
        y0 = 0;
    }
};


#endif //HMM_VAMPIRE_H
