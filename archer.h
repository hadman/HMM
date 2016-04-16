//
// Created by anton on 09.04.16.
//

#ifndef HMM_ARCHER_H
#define HMM_ARCHER_H


class archer : public virtual creature {
private:
    int arrow_damage; // урон от стрел
public:

    friend class skeleton_archer;

    friend class elf;

    virtual bool arrow_attack(creature *attacked_creature,
                              map &MAP) {  // возможность стрелять из лука. это существо может стрелять
        if (attacked_creature->alive) {
            attacked_creature->get_damage(arrow_damage, MAP); // наносит врагу урон стрелой.
        }
        return true;
    }

};


#endif //HMM_ARCHER_H
