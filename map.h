//
// Created by musta on 08.04.2016.
//

#ifndef HMM_MAP_H
#define HMM_MAP_H

#include "GameField.h"
#include "creature.h"
//#include "player.h"

using namespace std;

enum TileResource {
    TR_GRASS,
    TR_STONE,
    TR_DESERT
};

enum CreatureResource {
    CR_VAMPIRE,
    CR_ELF,
    CR_GNOME
};

class map {
private:
    int width;
    int height;
    unsigned int **map_of_id;
public:
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

    ~map() // Деструктор работает.
    {
        for (int k = 0; k < height; ++k) {
            delete map_of_id[k];
        }
        delete[] map_of_id;
    }

    void put_1_player(player &gamer) // расстановка первого игрока на карте
    {
        int x = 0; // координата по высоте
        int y = 0; // координата по ширине
        int i = 0; // счетчик

        while (i < gamer.creatureCount) // расставляем персонажей на карте. начиная слева сверху
        {
            map_of_id[x][y] = gamer.creatureMass[i]->get_id();
            gamer.creatureMass[i]->x0 = x;
            gamer.creatureMass[i]->y0 = y;

            i++;
            x = (x + 1) % height;
            if (x == 0) {
                y++;
            }
        }
    }

    void put_2_player(player &gamer) // расстановка второго игрока на карте
    {
        int x = 0; // координата по высоте
        int y = width - 1; // координата по ширине
        int i = 0; // счетчик

        while (i < gamer.creatureCount) // расставляем персонажей на карте. начиная слева сверху
        {
            map_of_id[x][y] = gamer.creatureMass[i]->get_id();
            gamer.creatureMass[i]->x0 = x;
            gamer.creatureMass[i]->y0 = y;
            i++;
            x = (x + 1) % height;
            if (x == 0) {
                y--;
            }
        }
    }

    void print_map() {
        for (int i = 0; i < height; ++i) {
            for (int j = 0; j < width; ++j) {
                cout << map_of_id[i][j] << " ";
            }
            cout << endl;
        }
    }

    unsigned int get_creature_ID(int x, int y) // возвращает ID персонажа в клетке.
    {
        return map_of_id[x - 1][y - 1];
    };
};


#endif //HMM_MAP_H
