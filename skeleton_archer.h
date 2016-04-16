//
// Created by anton on 09.04.16.
//

#ifndef HMM_SKELETON_ARCHER_H
#define HMM_SKELETON_ARCHER_H

#include "undead.h"
#include "archer.h"
#include "warrior.h"

class skeleton_archer : public undead, public archer, public warrior {
public:
    skeleton_archer(unsigned int id) {
        alive = true;
        path_length = 3;
        ID = id;
        health = 5;
        damage = 10;
        defense = 5;
    };

};


#endif //HMM_SKELETON_ARCHER_H
