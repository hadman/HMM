//
// Created by musta on 08.04.2016.
//

#ifndef HMM_MAP_H
#define HMM_MAP_H

#include "GameField.h"

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
public:
    static int m_layer1[7][14] = { // куда можно наступить
            {0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0, 0, 0},
            {0, 0, 0, 0, 0, 0, 1, 0, 1, 0, 0, 0, 0, 0},
            {0, 0, 0, 0, 0, 0, 1, 0, 1, 0, 0, 0, 0, 0},
            {0, 0, 0, 0, 0, 0, 1, 0, 1, 0, 0, 0, 0, 0},
            {0, 0, 0, 0, 0, 1, 1, 0, 1, 1, 0, 0, 0, 0},
            {0, 0, 0, 0, 1, 0, 0, 1, 0, 0, 1, 0, 0, 0},
            {0, 0, 0, 0, 0, 1, 1, 0, 1, 1, 0, 0, 0, 0},
    };
    static TileResource m_layer2[7][14] = { // текстура
            {TR_GRASS, TR_GRASS, TR_GRASS, TR_GRASS, TR_GRASS, TR_GRASS, TR_GRASS, TR_GRASS, TR_GRASS, TR_GRASS, TR_GRASS, TR_GRASS, TR_GRASS, TR_GRASS},
            {TR_GRASS, TR_GRASS, TR_GRASS, TR_GRASS, TR_GRASS, TR_GRASS, TR_GRASS, TR_GRASS, TR_GRASS, TR_GRASS, TR_GRASS, TR_GRASS, TR_GRASS, TR_GRASS},
            {TR_GRASS, TR_GRASS, TR_GRASS, TR_GRASS, TR_GRASS, TR_GRASS, TR_GRASS, TR_GRASS, TR_GRASS, TR_GRASS, TR_GRASS, TR_GRASS, TR_GRASS, TR_GRASS},
            {TR_GRASS, TR_GRASS, TR_GRASS, TR_GRASS, TR_GRASS, TR_GRASS, TR_GRASS, TR_GRASS, TR_GRASS, TR_GRASS, TR_GRASS, TR_GRASS, TR_GRASS, TR_GRASS},
            {TR_GRASS, TR_GRASS, TR_GRASS, TR_GRASS, TR_GRASS, TR_GRASS, TR_GRASS, TR_GRASS, TR_GRASS, TR_GRASS, TR_GRASS, TR_GRASS, TR_GRASS, TR_GRASS},
            {TR_GRASS, TR_GRASS, TR_GRASS, TR_GRASS, TR_GRASS, TR_GRASS, TR_GRASS, TR_GRASS, TR_GRASS, TR_GRASS, TR_GRASS, TR_GRASS, TR_GRASS, TR_GRASS},
            {TR_GRASS, TR_GRASS, TR_GRASS, TR_GRASS, TR_GRASS, TR_GRASS, TR_GRASS, TR_GRASS, TR_GRASS, TR_GRASS, TR_GRASS, TR_GRASS, TR_GRASS, TR_GRASS}
    };
    static int m_layer3[7][14] = { // находится ли на клетке какой-либо персонаж
            {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
            {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
            {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
            {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
            {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0},
            {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
            {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1}
    };
    static creature m_layer4[7][14] = { // какие именно персонажи
            {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
            {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
            {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
            {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
            {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0},
            {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
            {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1}
    };

    static bool isItEmpty(int x, int y) // 0 - empty; 1- not empty
    {
        return m_layer3[x][y];
    }

    static creature get_creature
};


#endif //HMM_MAP_H
