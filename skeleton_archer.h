//
// Created by anton on 09.04.16.
//

#ifndef HMM_SKELETON_ARCHER_H
#define HMM_SKELETON_ARCHER_H


class skeleton_archer : public warrior, public archer {
public:
    skeleton_archer(unsigned int id) {
        skin = LoadImage("skeleton.png");
        if (skin == NULL)
            cout << "skeleton not found " << endl;
        alive = true;
        path_length = 3;
        ID = id;
        health = 10;
            start_hp = health;
        damage = 9;
        damage_max = 11;
        arrow_damage = 12;
        arrow_damage_max = 14;
        defense = 9;
        race = "skeleton_archer";
    };

};


#endif //HMM_SKELETON_ARCHER_H
