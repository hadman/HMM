//
// Created by anton on 09.04.16.
//

#ifndef HMM_SKELETON_ARCHER_H
#define HMM_SKELETON_ARCHER_H


class skeleton_archer : public undead, public archer, public warrior {
public:
    skeleton_archer(unsigned int id) {
        alive = true;
        path_length = 3;
        ID = id;
        health = 10;
            start_hp = health;
        damage = 10;
        arrow_damage = 13;
        defense = 9;
        race = "skeleton_archer";
    };

};


#endif //HMM_SKELETON_ARCHER_H
