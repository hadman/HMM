

#ifndef HMM_WARRIOR_H
#define HMM_WARRIOR_H


class warrior : public virtual creature // виртуальное наследование для решения проблемы ромбовидного наследования
{
private:
//    int damage;
    //урон, наносимый существом
public:
    friend class elf;

    friend class vampire;

    friend class monk;

    friend class skeleton_archer;

    virtual bool attack(creature *attacked_creature, map &MAP) {  // возможность атаковать. это существо может атаковать
        if (attacked_creature->alive) {
            attacked_creature->get_damage(this->damage, MAP); // наносит врагу урон обычной атакой.
        }
        return true;
    }
};

#endif //HMM_WARRIOR_H
