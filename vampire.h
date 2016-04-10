//
// Created by anton on 08.04.16.
//

#ifndef HMM_VAMPIRE_H
#define HMM_VAMPIRE_H

#include "undead.h"

class vampire : public undead {
public:
    virtual void attack(creature another) {
        if (another.alive) {
            unsigned int regeneration = another.get_damage(*this);
            health += regeneration;
        }
    }

    vampire(unsigned int id) {
        alive = true;
        ID = id;
        health = 5;
        cout << "vampire created!" << endl;
    }
};


#endif //HMM_VAMPIRE_H
