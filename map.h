//
// Created by musta on 08.04.2016.
//
//В карте хранится информация о существах, их местоположении.
//Она НЕ может передвигать существ, т.к. является лишь статическим отображением ситуации, происходящей на поле битвы
//она может стереть или поставить существо на новую позицию, если существо сказало ей об этом

#ifndef HMM_MAP_H
#define HMM_MAP_H

#include "player.h"

using namespace std;

enum TileResource {
    //цвет поля в данной клетке
    TR_GRASS,
    TR_STONE,
    TR_DESERT
};

enum CreatureResource {
    CR_VAMPIRE,
    CR_ELF,
    CR_GNOME
};

class creature;

class map {
private:
    static int width;
    static int height;
    static unsigned int **map_of_id;
public:

    friend class player;

    friend class creature;

    friend class the_game;

    map(int x, int y) // создание карты и заполнение всех полей нулями y- ширина. x - высота
    {
        height = x; // высота карты
        width = y; // ширина карты

        map_of_id = new unsigned int *[height];

        for (int i = 0; i < height; ++i) {
            map_of_id[i] = new unsigned int[width];
        }

        for (int j = 0; j < height; ++j) {
            for (int i = 0; i < width; ++i) {
                map_of_id[j][i] = 0;
            }
        }
    }

    ~map() // Деструктор
    {
        for (int k = 0; k < height; ++k) {
            delete map_of_id[k];
        }
        delete[] map_of_id;
    }

    void print_map() {
        cout << "x/y ";
        for (int k = 0; k < width; ++k) {
            cout << k << " ";
        }
        cout << endl;
        cout << endl;
        for (int i = 0; i < height; ++i) {
            cout << i << "   ";
            for (int j = 0; j < width; ++j) {
                cout << map_of_id[i][j] << " ";
            }
            cout << endl;
        }
    }

    unsigned int get_creature_ID(int x, int y) // возвращает ID персонажа в клетке.
    {
        return map_of_id[x - 1][y - 1];
    }


    bool is_this_point_empty(int x, int y) // проверяет постая ли клетка. Пустая: true; Не пустая: false
    {
        if (map_of_id[x][y] == 0) {
            return true;
        } else {
            return false;
        }
    }


    unsigned int get_id_of_point(int x, int y) {
        return map_of_id[x][y];
    }

    static void wipe_from_map(int x0, int y0) // удаление персонажа с карты
    {
        map_of_id[x0][y0] = 0;
    }


};


#endif //HMM_MAP_H
