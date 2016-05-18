//
// Created by musta on 16.04.2016.
//

#ifndef HMM_ELF_H
#define HMM_ELF_H


#include "archer.h"
#include "warrior.h"

class elf : public warrior, public archer {
public:
    elf(unsigned int id) {
        skin = LoadImage("elf.png");
        if (skin == NULL)
            cout << "elf not found " << endl;
        alive = true;
        path_length = 3;
        ID = id;
        health = 10;
            start_hp = health;
        damage = 12;
        arrow_damage = 14;
        defense = 9;
        race = "elf";
    }
};

#endif //HMM_ELF_H
