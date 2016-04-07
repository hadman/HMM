//
// Created by anton on 07.04.16.
//

#ifndef HMM_CREATURE_H
#define HMM_CREATURE_H


class creature {
protected:
    unsigned int health;
    //количество очков здоровья
    unsigned int damage;
    //урон, наносимый существом
    unsigned int defense;
    //защита - то, сколько урона существо может предотвратить
    unsigned int path_length;
    //длина хода
    unsigned int x;
    //абцисса координаты, на которой находится существо
    unsigned int y;
    //ордината координаты, на которой находится существо
    bool alive;
    //живо существо(1) или нет(0)
    unsigned char belong_to;//принадлежность к 1 или 2 игроку
public:
    virtual void attack(creature another);

    virtual bool get_damage(creature another);

    virtual bool move()
};


#endif //HMM_CREATURE_H
