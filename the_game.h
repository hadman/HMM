//
// Created by musta on 11.04.2016.
//

#ifndef HMM_THE_GAME_H
#define HMM_THE_GAME_H

//#include "map.h"

class the_game // ��������� �� 2-� ������� ������ ����� ����������.
    // ����� �� ����� ���������� ������,
    // ���������, ������ ��� ������� ���� ������� ������
    // �� ��� ��� ���� ���� �� ������ �� ���������� �� ���������� �����
{
private:
    vector<creature *> game_creature_Mas; // ������ ������� �� ���� ���
    int game_creature_Mas_Count;

    void make_game_mass(player &gamer1, player &gamer2) // ���������� ������� ����������
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

    bool is_this_creature_of_this_game(unsigned int creature_id) { // ��������� ���������� �� �������� � ����� id � ����
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

    void print_map() {
        // cout << setfill(' ') << setw(3)  << "x/y ";
        // for (int k = 0; k < width; ++k) {
        //     cout << setfill(' ') << setw(2) << k << " ";
        // }
        // cout << endl;
        // cout << endl;
        // for (int i = 0; i < height; ++i) {
        //     cout << setfill(' ') << setw(1) << i << "   ";
        //     for (int j = 0; j < width; ++j) {
        //         cout << setfill(' ') << setw(2) << map_of_id[i][j] << " ";
        //     }
        //     cout << endl;
        // }
        SDL_RenderClear(renderer);

        for (int i = 0; i < game_creature_Mas_Count; i++)
            if (game_creature_Mas[i]->alive)
                ApplySurface(game_creature_Mas[i]->y0 * 85, game_creature_Mas[i]->x0 * 95, game_creature_Mas[i]->skin,
                             renderer);

//ApplySurface(rand() % 300,rand() % 300,game_creature_Mas[0]->skin,renderer);
        SDL_RenderPresent(renderer); // ������ ������������ ������
        SDL_Delay(100);


    }

    the_game(player &gamer1, player &gamer2) //
    {
        make_game_mass(gamer1, gamer2);
        game_creature_Mas_Count = game_creature_Mas.size();
    }

    bool start(player &gamer1, player &gamer2, SDL_Renderer *GAMErenderer) {

        cout << "POSHUMIM BLEAT!!!" << endl;
        cout << "GAME START" << endl;
        int i = 0;
        int inp_x;
        int inp_y;
        bool is_it_enemy; // true: ����� �������. false: ������ �������

        int tmp_x; // �������, � ������� ����� ������� ���������
        int tmp_y;

        int check; // ��������
        bool ext = true;

        SDL_Event ev;

        const Uint8 *keyState;

//        bool is_point_empty; // true: ������ ������. false: �� ������

        creature *tmp_creature; // ����� ��������� ���������

        // for (int z=1; z< 4;z++)
        // {
        //     print_map();
        //     Sleep(10000);
        // };

        // while (true)
        // {
        //   print_map();
        // }

        while (gamer1.count_of_creatures() > 0 &&
               gamer2.count_of_creatures() > 0 &&  // ���� ���� �� ��� ��� ���� � ����� ���������� ���� ����� ������
               ext)
        {
            if (game_creature_Mas[i]->alive) // ��� ������ ������ ����� ����������
            {
                cout << endl;
                cout << "RACE:" << game_creature_Mas[i]->race << ";  ID:" << game_creature_Mas[i]->ID << endl;
                cout << "path length of creature:" << game_creature_Mas[i]->path_length << endl;

                string text = "";
                SDL_StartTextInput();
                do {
                    repeat_input:;
                    check = true;
                    // if (game_creature_Mas[i]->belong_to == 1) // ����� ������ �����
                    // {
                    //     cout << "the course of player I:" << endl;
                    //     check = (gamer1.input_position(inp_x, inp_y)); // ���� ���������� ������� �� �������
                    // } else {
                    //     cout << "the course of player II:" << endl;
                    //     check = gamer2.input_position(inp_x, inp_y); // ���� ���������� ������� �� �������
                    // }
                    // SDL_StartTextInput();
                    //Sleep(10000);
                    // inp_x = rand() % 5;
                    // inp_y = rand() % 10;


                    while (SDL_PollEvent(&ev) != 0)
                    {
                        if (ev.type == SDL_QUIT) // �������� ����
                        {
                            ext = false;
                            return 0;
                        } else if (ev.type == SDL_TEXTINPUT ||
                                   ev.type == SDL_KEYDOWN) // ���� ������ ��� ������ ������� �������
                        {
                            system("cls");
                            if (ev.type == SDL_KEYDOWN && ev.key.keysym.sym == SDLK_BACKSPACE && text.length() > 0)
                                text = text.substr(0, text.length() - 1);
                            else if (ev.type == SDL_KEYDOWN && ev.key.keysym.sym == SDLK_RETURN)
                                text = "";
                            else if (ev.type == SDL_TEXTINPUT)
                                text += ev.text.text;


                            cout << text << endl;
                        }
                        if (ev.type == SDL_MOUSEBUTTONDOWN) // ������� ������ ����
                        {
                            if (ev.button.button == SDL_BUTTON_LEFT) {
                                inp_y = ev.button.x / 85;
                                inp_x = ev.button.y / 95;
                                cout << "LEFT BUTTON PRESSED! at x: " << ev.button.x << " y: " << ev.button.y << endl;
                                cout << "inp_x: " << inp_x << " inp_y: " << inp_y << endl;
                                goto try_to_do_step;
                            }
                        };
                    }

                    keyState = SDL_GetKeyboardState(NULL);


                    print_map();
                    goto repeat_input;

                    if (check == 0) // ���� ���������� ������� �����������
                    {
                        cout << "ERROR: this position is't on the map" << endl;
                        goto repeat_input;
                    }
                    if (check == -1) // ���� ����� ����� ���������� ���
                    {
                        cout << "You missed your turn" << endl;
                        break;
                    }

                    try_to_do_step:;

                    if (!(map::is_this_point_empty(inp_x, inp_y))) // ���� ������ ��������
                    {
//                        is_point_empty = false; // ������ ��������
                        tmp_creature = return_creature_by_id(
                                map::get_id_of_point(inp_x, inp_y)); // ������� ����� ��������� �� ��������� ������
                        if (game_creature_Mas[i]->belong_to ==
                            tmp_creature->belong_to)          // ���� ��� ����
                        {
                            if (game_creature_Mas[i]->add_hp(
                                    tmp_creature)) // ���� ���� �������� ����� ��������������� ��������
                            {
                                cout << "ATTACK: I add hp to " << tmp_creature->ID << endl;
                            } else {
                                cout << "ERROR: this creature is your friend" << endl;
                                goto repeat_input;
                            }
                        } else {
                            if (game_creature_Mas[i]->arrow_attack(tmp_creature)) // ���� ���� �������� ����� ��������
                            {
                                cout << "ATTACK: I shot a " << tmp_creature->ID << endl;
                            } else // ���������� ������� � ����
                            {
                                if (!(game_creature_Mas[i]->can_creature_move_to_point(inp_x,
                                                                                       inp_y)))// ��������� � ���� ������������ �� ��������� ����������
                                {
                                    cout << "ERROR: this creature can't move so far" << endl;
                                    goto repeat_input;
                                } else // ���� �������� � ���� ������������
                                {
                                    if ((abs(game_creature_Mas[i]->x0 - inp_x) <= 1) &&
                                        (abs(game_creature_Mas[i]->y0 - inp_y)) <=
                                        1) // ��������� ��������� �� ��������� �������� ��� � ������� ����� ������
                                    {
                                        if (game_creature_Mas[i]->attack(
                                                tmp_creature)) // ����� �� ��� �������� ���������
                                        {
                                            cout << "attackHere = " << tmp_creature->get_id() <<
                                            endl; // ������� ������� ���������� ��������� � ������
                                        } else {
                                            cout << "ERROR: this creature can't attack" << endl;
                                            goto repeat_input;
                                        }
                                    } else {
                                        if (search_empty_point(game_creature_Mas[i], tmp_creature, tmp_x,
                                                               tmp_y)) // ��������� ����� �� ������� � �������� ��������
                                        {
                                            if (game_creature_Mas[i]->attack(
                                                    tmp_creature)) // ����� �� ��� �������� ���������
                                            {
                                                cout << "attackThere = " << tmp_creature->get_id() <<
                                                endl; // ������� ������� ���������� ��������� � ������
                                                game_creature_Mas[i]->move(tmp_x, tmp_y);
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

                    } else // ����� � ��� ����� ��������
                    {
                        if (
                                !(game_creature_Mas[i]->can_creature_move_to_point(inp_x,
                                                                                   inp_y)))// ��������� � ���� ������������ �� ��������� ����������
                        {
                            cout << "ERROR: this creature can't move so far" << endl;
                            goto repeat_input;
                        } else {
                            game_creature_Mas[i]->move(inp_x, inp_y);
                        }
//                        is_point_empty = true; // ������ ������
                    }

                } while (false);
                SDL_StopTextInput();

                i = (i + 1) % game_creature_Mas_Count;
            } else {
                i = (i + 1) % game_creature_Mas_Count;
            }
            print_map();
        }

        cout << "RRRAAAUND!!!" << endl;
    }

    bool search_empty_point(creature *creature1, creature *creature2, int &x,
                            int &y) // ����� ��������� �����, ���� ����� ������ creature1, ����� ������� creature2. False: creature2 ������ �������
    {
        double distance = sqrt(width * width + height * height) + 10; // ���������� �� ���������
        bool found = false;                                   // �������� ������� �� ���� �� ���� ���������� ������
        for (int i = 0; i < height; ++i) {
            for (int j = 0; j < width; ++j) {
                if ((map_of_id[i][j] == 0) &&
                    // ������� ����� ������ ���� ������
                    (abs(creature1->x0 - i) < creature1->path_length) &&
                    // ������� ����� ������ ���� � ���� ����� creature1
                    (abs(creature1->y0 - j) < creature1->path_length) &&
                    (abs(creature2->x0 - i) <= 1) &&
                    // ������� ����� ������ ���� �������� � creature2
                    (abs(creature2->y0 - j) <= 1) &&
                    (creature1->distance_to_point(i, j) <
                     distance))               // ������� ����� ���������� �� ������ ���� ������ ��� � ���������� ������
                {
                    x = i;                                          // ��������� ����������
                    y = j;
                    cout << "new x = " << x << " new y = " << y << endl;
                    distance = creature1->distance_to_point(i, j);    // ��������� ����������
                    found = true;
                }
            }
        }
        return found;
    }


};

#endif //HMM_THE_GAME_H
