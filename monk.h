//
// Created by musta on 16.04.2016.
//

#ifndef HMM_MONK_H
#define HMM_MONK_H

#include "warrior.h"
#include "doctor.h"

class monk : public warrior, public doctor {
    monk(unsigned int id) {
        alive = true;
        path_length = 4;
        ID = id;
        health = 5;
        damage = 12;
        defense = 9;
        count_hp = 4;
    }
};


#endif //HMM_MONK_H
