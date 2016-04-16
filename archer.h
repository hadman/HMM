//
// Created by anton on 09.04.16.
//

#ifndef HMM_ARCHER_H
#define HMM_ARCHER_H


class archer : public virtual creature {
private:
    int arrow_damage; // урон от стрел
public:

    friend class skeleton_archer;

    friend class elf;


};


#endif //HMM_ARCHER_H
