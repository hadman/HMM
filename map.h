//
// Created by musta on 08.04.2016.
//

#ifndef HMM_MAP_H
#define HMM_MAP_H

#include <bits/stl_vector.h>
#include "GameField.h"
#include "creature.h"

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
//    vector< vector<unsigned int>> map_of_id;
    unsigned int **map_of_id;
public:
    map(int x, int y) {
        width = x; // ширина карты
        height = y; // высота карты
        map_of_id = new unsigned int *[height];
        unsigned int *map_of_id = new unsigned int[width];

        for (int i = 0; i < x; ++i) {
            for (int j = 0; j < y; ++j) {
                map_of_id[i][j] = 0;
            }
        }
    }


//    static int m_layer1[7][14] = { // куда можно наступить
//            {0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0, 0, 0},
//            {0, 0, 0, 0, 0, 0, 1, 0, 1, 0, 0, 0, 0, 0},
//            {0, 0, 0, 0, 0, 0, 1, 0, 1, 0, 0, 0, 0, 0},
//            {0, 0, 0, 0, 0, 0, 1, 0, 1, 0, 0, 0, 0, 0},
//            {0, 0, 0, 0, 0, 1, 1, 0, 1, 1, 0, 0, 0, 0},
//            {0, 0, 0, 0, 1, 0, 0, 1, 0, 0, 1, 0, 0, 0},
//            {0, 0, 0, 0, 0, 1, 1, 0, 1, 1, 0, 0, 0, 0},
//    };
//
//    static TileResource m_layer2[7][14] = { // текстура
//            {TR_GRASS, TR_GRASS, TR_GRASS, TR_GRASS, TR_GRASS, TR_GRASS, TR_GRASS, TR_GRASS, TR_GRASS, TR_GRASS, TR_GRASS, TR_GRASS, TR_GRASS, TR_GRASS},
//            {TR_GRASS, TR_GRASS, TR_GRASS, TR_GRASS, TR_GRASS, TR_GRASS, TR_GRASS, TR_GRASS, TR_GRASS, TR_GRASS, TR_GRASS, TR_GRASS, TR_GRASS, TR_GRASS},
//            {TR_GRASS, TR_GRASS, TR_GRASS, TR_GRASS, TR_GRASS, TR_GRASS, TR_GRASS, TR_GRASS, TR_GRASS, TR_GRASS, TR_GRASS, TR_GRASS, TR_GRASS, TR_GRASS},
//            {TR_GRASS, TR_GRASS, TR_GRASS, TR_GRASS, TR_GRASS, TR_GRASS, TR_GRASS, TR_GRASS, TR_GRASS, TR_GRASS, TR_GRASS, TR_GRASS, TR_GRASS, TR_GRASS},
//            {TR_GRASS, TR_GRASS, TR_GRASS, TR_GRASS, TR_GRASS, TR_GRASS, TR_GRASS, TR_GRASS, TR_GRASS, TR_GRASS, TR_GRASS, TR_GRASS, TR_GRASS, TR_GRASS},
//            {TR_GRASS, TR_GRASS, TR_GRASS, TR_GRASS, TR_GRASS, TR_GRASS, TR_GRASS, TR_GRASS, TR_GRASS, TR_GRASS, TR_GRASS, TR_GRASS, TR_GRASS, TR_GRASS},
//            {TR_GRASS, TR_GRASS, TR_GRASS, TR_GRASS, TR_GRASS, TR_GRASS, TR_GRASS, TR_GRASS, TR_GRASS, TR_GRASS, TR_GRASS, TR_GRASS, TR_GRASS, TR_GRASS}
//    };
//
//    static int m_layer3[7][14] = { // находится ли на клетке какой-либо персонаж
//            {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2},
//            {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2},
//            {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2},
//            {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2},
//            {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2, 0, 0, 0},
//            {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2},
//            {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2}
//    };


//    static bool is_empty(unsigned int x, unsigned int y) // 0 - empty; 1- not empty
//    {
//        return m_layer3[x][y];
//    }

    static unsigned int get_creature(unsigned int x, unsigned int y)
    {

        return 0;
    };
};


#endif //HMM_MAP_H
