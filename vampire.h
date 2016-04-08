//
// Created by anton on 08.04.16.
//

#ifndef HMM_VAMPIRE_H
#define HMM_VAMPIRE_H

#include "undead.h"

class vampire : public undead {
public:
    vampire();

    virtual void attack(creature another);
};


#endif //HMM_VAMPIRE_H
