//
// Created by musta on 16.04.2016.
//

#ifndef HMM_MONK_H
#define HMM_MONK_H


class monk : public warrior, public doctor {
public:
    monk(unsigned int id) {
        skin = LoadImage("monk.png");
        if (skin == NULL)
            cout << "monk not found " << endl;
        alive = true;
        path_length = 4;
        ID = id;
        health = 12;
            start_hp = health;
        damage = 11;
        damage_max = 13;
        defense = 9;
        count_hp = 3;
        count_hp_max = 5;
        race = "monk";
    }
};


#endif //HMM_MONK_H
