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
    int game_creature_Mas_Count;

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

    bool is_this_creature_of_this_game(unsigned int creature_id) {
        for (int i = 0; i < game_creature_Mas_Count; ++i) {
            if (game_creature_Mas[i]->get_id() == creature_id) {
                return true;
            }
        }
        return false;
    }

    creature *return_creature_by_id(unsigned int creature_id) {
        for (int i = 0; i < game_creature_Mas_Count; ++i) {
            if (game_creature_Mas[i]->get_id() == creature_id) {
                return game_creature_Mas[i];
            }
        }
    }
public:


    the_game(player &gamer1, player &gamer2, map &MAP) //
    {
        make_game_mass(gamer1, gamer2);
        game_creature_Mas_Count = game_creature_Mas.size();
    }

    void start(player &gamer1, player &gamer2, map &MAP) {
        cout << "POSHUMIM BLEAT!!!" << endl;
        int i = 0;
        int inp_x;
        int inp_y;
        bool is_it_enemy; // true: можно ударить. false: нельзя ударить

        creature *tmp_creature; // буфер временнго персонажа

        while (gamer1.count_of_creatures() > 0 &&
               gamer2.count_of_creatures() > 0) // игра идет до тех пор пока у обоих персонажей есть живые игроки
        {
            if (game_creature_Mas[i]->alive) // ход дается только живым персонажам
            {
                cout << "ID of creature: " << game_creature_Mas[i]->ID << endl;
                do {
                    dont_kill_friend:;
                    if (game_creature_Mas[i]->belong_to == 1) // ходит первый игрок
                    {
                        cout << "the course of player I:" << endl;
                        gamer1.input_position(inp_x, inp_y);
                    } else {
                        cout << "the course of player II:" << endl;
                        gamer2.input_position(inp_x, inp_y);
                    }


                    if (!MAP.can_creature_move_to_point(inp_x, inp_y,
                                                        *game_creature_Mas[i])) // проверяем в зоне досягаемости ли введенные координаты
                    {
                        cout << "ERROR: this creature can't move so far" << endl;
                    } else {
                        if (MAP.is_this_point_empty(inp_x, inp_y)) // если клетка пустая
                        {
                            MAP.move(game_creature_Mas[i], inp_x,
                                     inp_y); // переместить персонажа на карте. и присвоить ему новые координаты
                        } else {
                            if (is_this_creature_of_this_game(
                                    MAP.get_id_of_point(inp_x, inp_y))) // проверяем есть ли в этой клетке персонаж
                            {
                                tmp_creature = return_creature_by_id(
                                        MAP.get_id_of_point(inp_x,
                                                            inp_y)); // создаем копию персонажа из указанной клетки
                                if (game_creature_Mas[i]->belong_to == tmp_creature->belong_to) {
                                    cout << "ERROR: this creature is your friend" << endl;
                                    goto dont_kill_friend;
                                } else {
                                    cout << "attack = " << tmp_creature->get_id() << endl;
//                                    game_creature_Mas[i]->attack(*tmp_creature);
                                    MAP.attack(game_creature_Mas[i], tmp_creature);
                                }
                            }
                        }
                    }
                } while (!(MAP.can_creature_move_to_point(inp_x, inp_y,
                                                          *game_creature_Mas[i]))); // просив игрока вводить координаты до тех пор, пока они не попадут в радиус досягаемости

                MAP.print_map();

                i = (i + 1) % game_creature_Mas_Count;
            }
        }
        cout << "RRRAAAUND!!!" << endl;
    }

//    void print_mas() {
//        for (int i = 0; i < game_creature_Mas.size(); ++i) {
//            cout << game_creature_Mas[i]->get_id() << endl;
//        }
//    }

};

#endif //HMM_THE_GAME_H
