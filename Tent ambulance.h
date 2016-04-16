//
// Created by musta on 14.04.2016.
//

#ifndef HMM_TENT_AMBULANCE_H
#define HMM_TENT_AMBULANCE_H

#include "doctor.h"

class Tent_ambulance : public doctor // палатка скорой помощи. ничего не умеет кроме как лечить
{
private:
public:
    Tent_ambulance(unsigned int id) {
        alive = true;
        path_length = 0; // не может ходить
        ID = id;
            health = 7;
            start_hp = health;
        defense = 0; // нет защиты
        count_hp = 5; // сколько здоровья вылечивает
    }
};

#endif //HMM_TENT_AMBULANCE_H
