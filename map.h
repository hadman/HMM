//
// Created by musta on 08.04.2016.
//

#ifndef HMM_MAP_H
#define HMM_MAP_H

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

class creature;
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
                                    creature creature1) // проверяет находится ли заданная координата в зоне досягаемости хода персонажа
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

    void move(creature *creature1, int new_x, int new_y) // перемещает персонажа в указанную клетку
    {
        map_of_id[creature1->x0][creature1->y0] = 0; // удалили из прошлой клетки
        map_of_id[new_x][new_y] = creature1->ID;     // преместили в новую клетку
        creature1->move(new_x, new_y);
    }

    void attack(creature *attack_creature, creature *attacked_creature) {
        attack_creature->attack(*attacked_creature);
        if (attacked_creature->alive == false)  // если атакуемый умирает
        {
            cout << "suka ya ubil ego!!!" << endl;
            move(attack_creature, attacked_creature->x0, attacked_creature->y0); // встаем на его место
        }
    }

    void del_from_map(creature *creature1) // удаление персонажа с карты
    {
        map_of_id[creature1->x0][creature1->y0] = 0;
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
