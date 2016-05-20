//
// Created by musta on 09.04.2016.
//

#ifndef HMM_PLAYER_H
#define HMM_PLAYER_H


#include "creature.h"
#include <vector>
#include <iostream>


using namespace std;

class player // хранит в себе всех своих персонажей и их кол-во
{

protected:
    //creature **creatureMass;            // массив указателей на его персонажей
    vector<creature *> creatureMass;
    int creatureCount;                  // кол-во персонажей
    int playerNum;                      // номер игорока
public:
    friend class map;

    friend class the_game;

    player(int Num) {
        playerNum = Num;
        creatureCount = 0;
    }

    bool addCreature(creature *addCr) // добавление персонажа игроку
    {
        if (addCr->alive == true) {


//            creature **tmp = new creature *[creatureCount];
//            for (int i = 0; i < creatureCount; ++i) {
//                tmp[i] = creatureMass[i];
//            }
//            delete[] creatureMass;
//            creatureMass = new creature *[creatureCount + 1];
//            for (int i = 0; i < creatureCount; ++i) {
//                creatureMass[i] = tmp[i];
//            }
//            creatureMass[creatureCount] = addCr;


            creatureMass.push_back(addCr);
            creatureCount++;
            //delete[] tmp;



            if (playerNum == 1) {
                addCr->belong_to = 1;
                //cout << "smth add to first player" << endl;
            } else {
                addCr->belong_to = 2;
                //cout << "smth add to second player" << endl;
            }
            return true;
        } else {
            return false;
        }
    }

    int make_army()
    {
        int i = 0; // счетчик добавленных персонажей
        int inp_x;
        int inp_y;

        int check; // проверка

        SDL_Texture * bg = NULL; // текстура персонажа
        bg = LoadImage("field2.png");
        if (bg == NULL)
            cout << "bg not found " << endl;
        SDL_Texture * player_bg = NULL; // текстура персонажа
        player_bg = LoadImage("player_bg.png");
        if (player_bg == NULL)
            cout << "player_bg not found " << endl;
        SDL_Texture * console = NULL; // текстура консоли
        console = LoadImage("console.png");
        if (console == NULL)
            cout << "console not found " << endl;

        SDL_Event ev; // событие

        const Uint8* keyState;



        vector<creature *> choose_creature;

        vampire* tmp_vampire = new vampire(0);
        skeleton_archer* tmp_skeleton_archer = new skeleton_archer(0);
        monk* tmp_monk = new monk(0);
        elf* tmp_elf = new elf(0);
        Tent_ambulance* tmp_Tent_ambulance = new Tent_ambulance(0);

        choose_creature.push_back(tmp_vampire); // создается временный массив для выбора армии
        choose_creature.push_back(tmp_skeleton_archer);
        choose_creature.push_back(tmp_monk);
        choose_creature.push_back(tmp_elf);
        choose_creature.push_back(tmp_Tent_ambulance);






//        bool is_point_empty; // true: клетка пустая. false: не пустая

        //creature *tmp_creature; // буфер временнго персонажа
        string text = "";
        SDL_StartTextInput();



        while(i < 5)
        {
            repeat_input:;
            check = 1;
            while (SDL_PollEvent(&ev) != 0)
                    {
                        if (ev.type == SDL_QUIT) // закрытие окна
                        {
                            return 0;
                        }else if(ev.type == SDL_TEXTINPUT || ev.type == SDL_KEYDOWN) // ввод текста или просто нажание клавиши
                        {
                            system("cls");
                            if (ev.type == SDL_KEYDOWN && ev.key.keysym.sym == SDLK_BACKSPACE && text.length() > 0)
                                text = text.substr(0, text.length() - 1);
                            else if (ev.type == SDL_KEYDOWN && ev.key.keysym.sym == SDLK_RETURN)
                                {
                                    text = "";
                                    check = -1;
                                    goto try_to_do_step;
                                }
                            else if(ev.type == SDL_TEXTINPUT)
                                text += ev.text.text;


                            cout << text << endl;
                        }
                        if (ev.type == SDL_MOUSEBUTTONDOWN) // нажатие кнопки мыши
                        {
                            if(ev.button.button == SDL_BUTTON_LEFT)
                            {
                                if(ev.button.y >= 116 && ev.button.y <= 591) // нажатие по полю боя
                                {
                                   inp_y = ev.button.x / 85;
                                    inp_x = (ev.button.y - 116) / 95;
                                    cout << "LEFT BUTTON PRESSED! at x: " << ev.button.x  << " y: " << ev.button.y << endl;
                                    cout << "inp_x: " << inp_x  << " inp_y: " << inp_y << endl;
                                    goto try_to_do_step;
                                }else if(ev.button.y >= 591 && ev.button.y <= 591 + 40) // нижняя панель
                                {
                                    if(ev.button.x >= 781 && ev.button.x <= 850) // пропуск хода
                                        {
                                            check = -1;
                                            goto try_to_do_step;
                                        }
                                }

                            }
                        };
                    }

                    keyState = SDL_GetKeyboardState(NULL);

                    print(choose_creature, bg, player_bg, console);
                    goto repeat_input;

                    try_to_do_step:;

                    if (check == -1)
                    {
                        break;
                    }else if(inp_x == 4)
                    {

                    switch(inp_y)
                    {
                        case 0:
                            {
                                vampire* tmp_vampire = new vampire(creature_ID::get_id());
                                tmp_vampire->x0 = 0;
                                tmp_vampire->y0 = i;
                                addCreature(tmp_vampire);
                                i++;
                            } break;
                        case 1:
                            {
                                skeleton_archer* tmp_skeleton_archer = new skeleton_archer(creature_ID::get_id());
                                tmp_skeleton_archer->x0 = 0;
                                tmp_skeleton_archer->y0 = i;
                                addCreature(tmp_skeleton_archer);
                                i++;
                            } break;
                        case 2:
                            {
                                monk* tmp_monk = new monk(creature_ID::get_id());
                                tmp_monk->x0 = 0;
                                tmp_monk->y0 = i;
                                addCreature(tmp_monk);
                                i++;
                            } break;
                        case 3:
                            {
                                elf* tmp_elf = new elf(creature_ID::get_id());
                                tmp_elf->x0 = 0;
                                tmp_elf->y0 = i;
                                addCreature(tmp_elf);
                                i++;
                            } break;
                        case 4:
                            {
                                Tent_ambulance* tmp_Tent_ambulance = new Tent_ambulance(creature_ID::get_id());
                                tmp_Tent_ambulance->x0 = 0;
                                tmp_Tent_ambulance->y0 = i;
                                addCreature(tmp_Tent_ambulance);
                                i++;
                            } break;
                    }
                    };




                    //addCreature()
        }




        SDL_StopTextInput();

         return 0;

    }

    void print(vector<creature *> choose_creature, SDL_Texture * bg , SDL_Texture * player_bg, SDL_Texture * console) // рисует экран выбора армии
    {
        SDL_RenderClear(renderer);


        ApplySurface(0,0,bg,renderer);


        int Number = playerNum ;      // number to be converted to a string

        string belong_to_str;          // string which will contain the result

        ostringstream convert;   // stream used for the conversion

        convert << Number;      // insert the textual representation of 'Number' in the characters in the stream

        belong_to_str = convert.str(); // set 'Result' to the contents of the stream

        logs = "Please input 5 creatures of " +  belong_to_str + " player";
        ApplySurface(10,10,player_bg,renderer,playerNum);
        ApplySurface(0,591,console,renderer); // отрисовка консоли
        Print_Font(gFont, textColor, logs ,70,591+10, 15); // количество hp



        for (int i = 0;i < creatureCount ;i++ )
        if ( creatureMass[i]->alive)
            ApplySurface(creatureMass[i]->y0*85 ,creatureMass[i]->x0*95+116,creatureMass[i]->skin,renderer,1);

        for (int j = 0; j < choose_creature.size(); j++)
            {
                ApplySurface(j*85 ,4*95+116,choose_creature[j]->skin,renderer,1); // при добавлении персонажи всега смотрят влево
            };

        //ApplySurface(rand() % 300,rand() % 300,game_creature_Mas[0]->skin,renderer);
        SDL_RenderPresent(renderer); // рисуем получившийся рендер
        SDL_Delay(100);
    }

    bool delCreature(creature *addCr) // ищем персонажа по id и удаляем
    {
        for (int i = 0; i < creatureCount; ++i) {
            if (creatureMass[i]->get_id() == addCr->get_id()) {
                creatureMass.erase(creatureMass.begin() + i);
                return true;
            }
        }
        return false;
    }

    int input_position(int &inp_x, int &inp_y) {
        int x;
        int y;

        cout << "if you want to skip: input '-1'" << endl;

        cout << "X = ";
        cin >> x;
        cout << "Y = ";
        cin >> y;
        inp_x = x;
        inp_y = y;

        if ((inp_x == -1) || (inp_y == -1)) {
            return -1;
        }

        if ((inp_x >= height) || (inp_y >= width) || (inp_x < 0) ||
            (inp_y < 0)) // если введенные координаты выходят за границу поля
        {
            return 0;
        }
        return 1;
    };


    int count_of_creatures() {
        int i = 0;
        for (int j = 0; j < creatureCount; ++j) {
            if (creatureMass[j]->alive == true) {
                i++;
            }
        }
        return i;
    }

    bool is_this_creature_of_this_player(unsigned int creature_id) // проверяет, есть ли персонаж с таким номер у игрока
    {
        for (int i = 0; i < creatureCount; ++i) {
            if (creatureMass[i]->get_id() == creature_id) {
                return true;
            }
        }
        return false;
    }

    creature *return_creature_with_this_id(unsigned int creature_id) // возвращает персонажа по id
    {
        for (int i = 0; i < creatureCount; ++i) {
            if (creatureMass[i]->get_id() == creature_id) {
                return creatureMass[i];
            }
        }
    }

    void put_creatures_on_map() {
        if (playerNum == 1) // расстановка существ первого игрока на карте
        {
            int x = 0; // координата по высоте
            int y = 0; // координата по ширине
            int i = 0; // счетчик

            while (i < creatureCount) // расставляем персонажей на карте. начиная слева сверху
            {
                map_of_id[x][y] = creatureMass[i]->get_id();
                creatureMass[i]->x0 = x;
                creatureMass[i]->y0 = y;

                i++;
                x = (x + 1) % height;
                if (x == 0) {
                    y++;
                }
            }
        }
        else // расстановка существ второго игрока на карте
        {
            int x = 0; // координата по высоте
            int y = width - 1; // координата по ширине
            int i = 0; // счетчик

            while (i < creatureCount) // расставляем персонажей на карте. начиная слева сверху
            {
                map_of_id[x][y] = creatureMass[i]->get_id();
                creatureMass[i]->x0 = x;
                creatureMass[i]->y0 = y;
                i++;
                x = (x + 1) % height;
                if (x == 0) {
                    y--;
                }
            }
        }
    }


};

#endif //HMM_PLAYER_H
