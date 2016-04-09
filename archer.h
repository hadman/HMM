//
// Created by anton on 09.04.16.
//

#ifndef HMM_ARCHER_H
#define HMM_ARCHER_H


#include "creature.h"

class archer : creature {
public:

    bool move(double x, double y) {
        bool answer;

        if (!map.empty(x, y)) {//если клетка занята другим существом, то стреляем в него
            attack(map.get_creature(x, y));
            answer = true;
        }
        else {
            double metrics = abs(x0 - x) + abs(y0 - y);//вычисляем расстояние до точки с текущего положения существа

            if (metrics <= path_length) {//если существу хватает длины хода, то премещаем его
                answer = true;
                x0 = x;
                y0 = y;
            } else {//если недостаточно длины хода
                cout << "Too far. Creature`s path length = " << path_length << endl;
                answer = false;
            }
            return answer;

        }
    }
};


#endif //HMM_ARCHER_H
