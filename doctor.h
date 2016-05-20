//
// Created by musta on 14.04.2016.
//

#ifndef HMM_DOCTOR_H
#define HMM_DOCTOR_H


class doctor
        : public virtual creature // класс, который может лечить дружественных персонажей. сюда входит палатка скорой помощи и будет входить какой-нибудь лысый монах
{
private:

public:
    friend class monk;

    friend class Tent_ambulance;

    virtual bool add_hp(creature *another) // Восстановление здоровья персонажа. это сущеество лечит
    {
        cout << ID << " cure " << count_hp << " hp to " << another->ID << endl;
        int tmp_hp = generate_in(count_hp, count_hp_max); // расчет силы выстрела
            logs = race + "(" + intToStr(ID) + ") " + " cured: " + another->race + "(" + intToStr(another->ID) + ") " + "- " + intToStr(tmp_hp) + " hp.";
        another->health += tmp_hp;
        if (another->health > another->start_hp) // нельзя добавить существу больше здоровья, чем было при его создании
        {
            another->health = another->start_hp;
        }
        return true;
    }
};

#endif //HMM_DOCTOR_H
