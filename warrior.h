

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

    virtual bool attack(creature *attacked_creature) {  // возможность атаковать. это существо может атаковать
        if (attacked_creature->alive) {
            int tmp_dmg = generate_in(damage, damage_max); // расчет силы выстрела

            logs = race + "(" + intToStr(ID) + ") " + " attacked: " + attacked_creature->race + "(" + intToStr(attacked_creature->ID) + ") " + "- " + intToStr(tmp_dmg) + " hp.";

            attacked_creature->get_damage(tmp_dmg); // наносит врагу урон обычной атакой.
        }
        return true;
    }
};

#endif //HMM_WARRIOR_H
