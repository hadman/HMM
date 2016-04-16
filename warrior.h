

#ifndef HMM_WARRIOR_H
#define HMM_WARRIOR_H

#include "creature.h"

class warrior : public virtual creature // виртуальное наследование для решения проблемы ромбовидного наследования
{
public:


    virtual bool attack(creature &another) {  // возможность атаковать. это существо может атаковать
        if (another.alive) {
            another.get_damage(*this);
        }
        return true;
    }
};

#endif //HMM_WARRIOR_H
