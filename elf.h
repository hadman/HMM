//
// Created by musta on 16.04.2016.
//

#ifndef HMM_ELF_H
#define HMM_ELF_H


class elf : public archer, public warrior {
public:
    elf(unsigned int id) {
        alive = true;
        path_length = 10;
        ID = id;
        health = 5;
            start_hp = health;
        damage = 12;
        defense = 9;
    }
};

#endif //HMM_ELF_H
