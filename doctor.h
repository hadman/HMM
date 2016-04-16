//
// Created by musta on 14.04.2016.
//

#ifndef HMM_DOCTOR_H
#define HMM_DOCTOR_H

#include "creature.h"

class doctor
        : public virtual creature // класс, который может лечить дружественных персонажей. сюда входит палатка скорой помощи и будет входить какой-нибудь лысый монах
{
private:
    int count_hp; // сколько здоровья вылечивает
public:
    friend class monk;

    friend class Tent_ambulance;

    virtual bool add_hp(creature &another) // Восстановление здоровья персонажа. это сущеество лечит
    {
        cout << ID << " cure " << count_hp << " hp to " << another.ID << endl;
        return true;
    }
};

#endif //HMM_DOCTOR_H
