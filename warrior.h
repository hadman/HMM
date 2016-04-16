

#ifndef HMM_WARRIOR_H
#define HMM_WARRIOR_H


class warrior : public virtual creature // виртуальное наследование для решения проблемы ромбовидного наследования
{
public:


    virtual bool attack(creature *attacked_creature, map &MAP) {  // возможность атаковать. это существо может атаковать
        if (attacked_creature->alive) {
            attacked_creature->get_damage(this, MAP);
        }
        return true;
    }
};

#endif //HMM_WARRIOR_H
