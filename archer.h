//
// Created by anton on 09.04.16.
//

#ifndef HMM_ARCHER_H
#define HMM_ARCHER_H


#include "creature.h"

class archer : public virtual creature {
public:

    virtual bool attack_arrow(creature &another) // стрельба из лука.
    {
        if (another.alive) {
            another.get_damage(*this);
        }
        return true;
    }

    bool attack_arrow(creature *attack_creature, creature *attacked_creature) {
        bool tmp = attack_creature->attack_arrow(*attacked_creature);
        if (tmp) {
            if (attacked_creature->alive == false)  // если атакуемый умирает
            {
                cout << "suka ya ubil ego iz luka!!!" << endl;
            }
        }
        return tmp;
    }
};


#endif //HMM_ARCHER_H
