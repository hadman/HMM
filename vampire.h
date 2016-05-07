//
// Created by anton on 08.04.16.
//

#ifndef HMM_VAMPIRE_H
#define HMM_VAMPIRE_H


class vampire : public undead, public warrior {
public:
    virtual bool attack(creature *another) {
        if (another->alive) {
            cout << " another->damage = " << this->damage << endl;
            int regeneration = another->get_damage(this->damage) / 2;
            health += regeneration;
            cout << ID << " got " << regeneration << " hp" << endl;
        }
        return true;
    }

    vampire(unsigned int id) {
        skin = LoadImage("vampL.bmp");
        if (skin == NULL)
            cout << "vampire not found " << endl;
        alive = true;
        path_length = 10;
        ID = id;
        health = 15;
        start_hp = health;
        damage = 14;
        defense = 5;
        race = "vampire";
        //cout << "vampire created!" << endl;
    }
};


#endif //HMM_VAMPIRE_H
