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
    double path_length;
    //длина хода
    double x0;
    //абцисса координаты, на которой находится существо
    double y0;
    //ордината координаты, на которой находится существо
    bool alive;
    //живо существо(1) или нет(0)
    unsigned char belong_to;//принадлежность к 1 или 2 игроку
public:
    creature();

    virtual void attack(creature another);//1 - если убил существо

    virtual unsigned int get_damage(creature another);//1 - если существо погибло

    virtual bool move(double x, double y);
};


#endif //HMM_CREATURE_H
