//
// Created by musta on 11.04.2016.
//

#ifndef HMM_THE_GAME_H
#define HMM_THE_GAME_H

//#include "map.h"

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

    bool is_this_creature_of_this_game(unsigned int creature_id) { // проверяем учавствует ли персонаж с таким id в игре
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

        int tmp_x; // позиция, с которой можно ударить персонажа
        int tmp_y;

//        bool is_point_empty; // true: клетка пустая. false: не пустая

        creature *tmp_creature; // буфер временнго персонажа

        while (gamer1.count_of_creatures() > 0 &&
               gamer2.count_of_creatures() > 0) // игра идет до тех пор пока у обоих персонажей есть живые игроки
        {
            if (game_creature_Mas[i]->alive) // ход дается только живым персонажам
            {
                cout << "ID of creature: " << game_creature_Mas[i]->ID << endl;
                do {
                    repeat_input:;
                    if (game_creature_Mas[i]->belong_to == 1) // ходит первый игрок
                    {
                        cout << "the course of player I:" << endl;
                        gamer1.input_position(inp_x, inp_y);
                    } else {
                        cout << "the course of player II:" << endl;
                        gamer2.input_position(inp_x, inp_y);
                    }

                    if (!(MAP.is_this_point_empty(inp_x, inp_y))) // если клетка непустая
                    {
//                        is_point_empty = false; // клетка непустая
                        tmp_creature = return_creature_by_id(
                                MAP.get_id_of_point(inp_x, inp_y)); // создаем копию персонажа из указанной клетки
                        if (game_creature_Mas[i]->belong_to ==
                            tmp_creature->belong_to)          // если это друг
                        {
                            if (game_creature_Mas[i]->add_hp(
                                    *tmp_creature)) // если этот персонаж умеет восстанавливать здоровье
                            {
                                cout << "ATTACK: I add hp to " << tmp_creature->ID << endl;
                            } else {
                                cout << "ERROR: this creature is your friend" << endl;
                                goto repeat_input;
                            }
                        } else {
                            if (game_creature_Mas[i]->arrow_attack(tmp_creature,
                                                                   MAP)) // если этот персонаж умеет стрелять
                            {
                                cout << "ATTACK: I shot a " << tmp_creature->ID << endl;
                            } else // попытаемся подойти к нему
                            {
                                if (!(game_creature_Mas[i]->can_creature_move_to_point(inp_x,
                                                                                       inp_y)))// проверяем в зоне досягаемости ли введенные координаты
                                {
                                    cout << "ERROR: this creature can't move so far" << endl;
                                    goto repeat_input;
                                } else // если персонаж в зоне досягаемости
                                {
                                    if ((abs(game_creature_Mas[i]->x0 - inp_x) <= 1) &&
                                        (abs(game_creature_Mas[i]->y0 - inp_y) <=
                                         1)) // проверяем находится ли утакуевое существо уже в радиусе одной клетки
                                    {
                                        if (game_creature_Mas[i]->attack(tmp_creature,
                                                                         MAP)) // умеет ли это существо атаковать
                                        {
                                            cout << "attackHere = " << tmp_creature->get_id() <<
                                            endl; // атакуем текущим персонажем персонажа в клетке
                                        } else {
                                            cout << "ERROR: this creature can't attack" << endl;
                                            goto repeat_input;
                                        }
                                    } else {
                                        if (search_empty_point(game_creature_Mas[i], tmp_creature, tmp_x,
                                                               tmp_y,
                                                               MAP)) // проверяет можно ли подойти к существу вплотную
                                        {
                                            if (game_creature_Mas[i]->attack(tmp_creature,
                                                                             MAP)) // умеет ли это существо атаковать
                                            {
                                                cout << "attackThere = " << tmp_creature->get_id() <<
                                                endl; // атакуем текущим персонажем персонажа в клетке
                                                game_creature_Mas[i]->move(tmp_x, tmp_y, MAP);
                                            } else {
                                                cout << "ERROR: this creature can't attack" << endl;
                                                goto repeat_input;
                                            }
                                        } else {
                                            cout << "ERROR: you can't attack this creature" << endl;
                                            goto repeat_input;
                                        }
                                    }
                                }
                            }
                        }

                    } else // тогда в нее нужно походить
                    {
                        if (
                                !(game_creature_Mas[i]->can_creature_move_to_point(inp_x,
                                                                                   inp_y)))// проверяем в зоне досягаемости ли введенные координаты
                        {
                            cout << "ERROR: this creature can't move so far" << endl;
                            goto repeat_input;
                        } else {
                            game_creature_Mas[i]->move(inp_x, inp_y, MAP);
                        }
//                        is_point_empty = true; // клетка пустая
                    }
                } while (false);

                MAP.print_map();

                i = (i + 1) % game_creature_Mas_Count;
            }
        }
        cout << "RRRAAAUND!!!" << endl;
    }

    bool search_empty_point(creature *creature1, creature *creature2, int &x,
                            int &y,
                            map &MAP) // поиск ближайшей точки, куда может встать creature1, чтобы ударить creature2. False: creature2 нельзя ударить
    {
        double distance = sqrt(MAP.width * MAP.width + MAP.height * MAP.height) + 10; // расстояние по умолчанию
        bool found = false;                                   // проверка найдена ли хотя бы одна свободаная клетка
        for (int i = 0; i < MAP.height; ++i) {
            for (int j = 0; j < MAP.width; ++j) {
                if ((MAP.map_of_id[i][j] == 0) &&
                    // смотрит чтобы клетка была пустой
                    (abs(creature1->x0 - i) < creature1->path_length) &&
                    // смотрит чтобы клетка была в зоне удара creature1
                    (abs(creature1->y0 - j) < creature1->path_length) &&
                    (abs(creature2->x0 - i) <= 1) &&
                    // смотрит чтобы клетка была соседней с creature2
                    (abs(creature2->y0 - j) <= 1) &&
                    (creature1->distance_to_point(i, j) <
                     distance))               // смотрит чтобы расстояние до клетки было меньше чем в предыдущем случае
                {
                    x = i;                                          // сохраняем координаты
                    y = j;
                    cout << "new x = " << x << " new y = " << y << endl;
                    distance = creature1->distance_to_point(i, j);    // сохраняем расстояние
                    found = true;
                }
            }
        }
        return found;
    }


};

#endif //HMM_THE_GAME_H
