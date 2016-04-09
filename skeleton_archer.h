//
// Created by anton on 09.04.16.
//

#ifndef HMM_SKELETON_ARCHER_H
#define HMM_SKELETON_ARCHER_H

#include "undead.h"
#include "archer.h"

class skeleton_archer : public undead {
public:
    skeleton_archer() { };

    friend bool archer::move();
}

};


#endif //HMM_SKELETON_ARCHER_H
