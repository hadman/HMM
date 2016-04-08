//
// Created by anton on 08.04.16.
//

#ifndef HMM_UNDEAD_H
#define HMM_UNDEAD_H

#include "creature.h"


class undead : public creature {
protected:
    unsigned int death_aura;//после убийства нежити, противнику наносится урон, равный death aura
public:
    virtual unsigned int get_damage(creature another);
};


#endif //HMM_UNDEAD_H
