//
// Created by musta on 11.04.2016.
//

#ifndef HMM_THE_GAME_H
#define HMM_THE_GAME_H

class the_game // формирует из 2-х игроков список ходов персонажей.
    // Ходит по этому кольцевому списку,
    // заставляя, делать ход первого либо второго игрока
    // до тех пор пока хотя бы одного из персонажей не закончится армия
{
private:
    vector<creature *> game_creature_Mas; // список существ на поле боя
public:
    void make_game_mass(player &gamer1, player &gamer2) // заполнение массива персонажей
    {
        int i;
        for (i = 0; i < min(gamer1.count_of_creatures(), gamer2.count_of_creatures()); ++i) {
            game_creature_Mas.push_back(gamer1.creatureMass[i]);
            game_creature_Mas.push_back(gamer2.creatureMass[i]);
        }
//        cout << "i = " << i << endl;
        for (int j = i; j < max(gamer1.count_of_creatures(), gamer2.count_of_creatures()); ++j) {
            if (gamer1.count_of_creatures() > gamer2.count_of_creatures()) {
                game_creature_Mas.push_back(gamer1.creatureMass[j]);
            } else {
                game_creature_Mas.push_back(gamer2.creatureMass[j]);
            }
        }
    }

    the_game(player &gamer1, player &gamer2, map &MAP) //
    {

    }

    void print_mas() {
        for (int i = 0; i < game_creature_Mas.size(); ++i) {
            cout << game_creature_Mas[i]->get_id() << endl;
        }
    }

};

#endif //HMM_THE_GAME_H
