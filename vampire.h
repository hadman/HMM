//
// Created by anton on 08.04.16.
//

#ifndef HMM_VAMPIRE_H
#define HMM_VAMPIRE_H


class vampire : public undead, public warrior {
public:
    virtual bool attack(creature *another, map &MAP) {
        if (another->alive) {
            int regeneration = another->get_damage(this, MAP) / 2;
            health += regeneration;
            cout << ID << " got " << regeneration << " hp" << endl;
        }
        return true;
    }

    vampire(unsigned int id) {
        alive = true;
        path_length = 10;
        ID = id;
        health = 5;
        damage = 12;
        defense = 9;
        //cout << "vampire created!" << endl;
    }
};


#endif //HMM_VAMPIRE_H
