//
// Created by musta on 08.04.2016.
//
//В карте хранится информация о существах, их местоположении.
//Она НЕ может передвигать существ, т.к. является лишь статическим отображением ситуации, происходящей на поле битвы
//она может стереть или поставить существо на новую позицию, если существо сказало ей об этом

#ifndef HMM_MAP_H
#define HMM_MAP_H


#include <iomanip>

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

static int width = 0;
static int height = 0;
static int **map_of_id = NULL;//карта id существ

class map {
public:

    static void make_map(int x, int y) // создание карты и заполнение всех полей нулями y- ширина. x - высота
    {
        height = x; // высота карты
        width = y; // ширина карты

        map_of_id = new int *[height];

        for (int i = 0; i < height; ++i) {
            map_of_id[i] = new int[width];
        }

        for (int j = 0; j < height; ++j) {
            for (int i = 0; i < width; ++i) {
                map_of_id[j][i] = 0;
            }
        }
    }

    static void destroy_map() // Деструктор
    {
        for (int k = 0; k < height; ++k) {
            delete map_of_id[k];
        }
        delete[] map_of_id;
    }

//    static void print_map() {
//        cout << setfill(' ') << setw(3)  << "x/y ";
//        for (int k = 0; k < width; ++k) {
//            cout << setfill(' ') << setw(2) << k << " ";
//        }
//        cout << endl;
//        cout << endl;
//        for (int i = 0; i < height; ++i) {
//            cout << setfill(' ') << setw(1) << i << "   ";
//            for (int j = 0; j < width; ++j) {
//                cout << setfill(' ') << setw(2) << map_of_id[i][j] << " ";
//            }
//            cout << endl;
//        }
//    }

    static unsigned int get_creature_ID(int x, int y) // возвращает ID персонажа в клетке.
    {
        return map_of_id[x - 1][y - 1];
    };

    static bool is_this_point_empty(int x, int y) // проверяет постая ли клетка. Пустая: true; Не пустая: false
    {
        if (map_of_id[x][y] == 0) {
            return true;
        } else {
            return false;
        }
    }


    static unsigned int get_id_of_point(int x, int y) {
        return map_of_id[x][y];
    }

    static void wipe_from_map(int x, int y) {
        map_of_id[x][y] = 0;
    }



//    static void del_from_map(creature &creature1) // удаление персонажа с карты
//    {
//        map_of_id[creature1.x0][creature1.y0] = 0;
//    }


};


#endif //HMM_MAP_H
