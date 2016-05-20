//
// Created by anton on 08.04.16.
//

#ifndef HMM_VAMPIRE_H
#define HMM_VAMPIRE_H


class vampire : public warrior {
public:
    virtual bool attack(creature *another) {
        if (another->alive) {
            cout << " another->damage = " << this->damage << endl;
            int tmp_dmg = generate_in(damage, damage_max); // расчет силы выстрела
            logs = race + "(" + intToStr(ID) + ") " + " attacked: " + another->race + "(" + intToStr(another->ID) + ") " + "- " + intToStr(tmp_dmg) + " hp.";
            int regeneration = another->get_damage(tmp_dmg) / 2;
            health += regeneration;
            if (health > start_hp) // нельзя добавить существу больше здоровья, чем было при его создании
            {
                health = start_hp;
            }

            cout << ID << " got " << regeneration << " hp" << endl;
        }
        return true;
    }


    vampire(unsigned int id) {
        skin = LoadImage("vamp.png");
        if (skin == NULL)
            cout << "vampire not found " << endl;
        alive = true;
        path_length = 10;
        ID = id;
        health = 15;
        start_hp = health;
        damage = 13;
        damage_max = 15;
        defense = 5;
        race = "vampire";
        //cout << "vampire created!" << endl;
    }
};


#endif //HMM_VAMPIRE_H
