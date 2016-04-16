//
// Created by musta on 08.04.2016.
//
//В карте хранится информация о существах, их местоположении.
//Она НЕ может передвигать существ, т.к. является лишь статическим отображением ситуации, происходящей на поле битвы
//она может стереть или поставить существо на новую позицию, если существо сказало ей об этом

#ifndef HMM_MAP_H
#define HMM_MAP_H

#include "creature.h"
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
    };

    bool can_creature_move_to_point(int x, int y,
                                    creature &creature1) // проверяет находится ли заданная координата в зоне досягаемости хода персонажа
    {
        if ((abs(creature1.x0 - x) >= creature1.path_length) || (abs(creature1.y0 - y) >= creature1.path_length)) {
            return false;
        }
        return true;
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

    double distance_to_point(creature &cr, int x, int y) // возвращает расстояние от точки (x,y) до персонажа
    {
        return sqrt(abs(x - cr.x0) + abs(y - cr.y0));
    }

    static void del_from_map(creature &creature1) // удаление персонажа с карты
    {
        map_of_id[creature1.x0][creature1.y0] = 0;
    }

    bool search_empty_point(creature *creature1, creature *creature2, int &x,
                            int &y) // поиск ближайшей точки, куда может встать creature1, чтобы ударить creature2. False: creature2 нельзя ударить
    {
        double distance = sqrt(width * width + height * height) + 10; // расстояние по умолчанию
        bool found = false;                                   // проверка найдена ли хотя бы одна свободаная клетка
        for (int i = 0; i < height; ++i) {
            for (int j = 0; j < width; ++j) {
                if ((map_of_id[i][j] == 0) &&                                        // смотрит чтобы клетка была пустой
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


#endif //HMM_MAP_H
