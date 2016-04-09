#include <iostream>

#include "creature.h"

#include "vampire.h"

using namespace std;

int main() {

    creature monster;

    vampire vamp;


    double x, y;

    cout << "Input x:";
    cin >> x;

    cout << "Input y:";
    cin >> y;

    if (x != 0 && y != 0) {

        //if (!monster.move(x, y)) {//запрашиваем координаты, пока не будут введены подходящие

            cout << "Input x:";
            cin >> x;

            cout << "Input y:";
            cin >> y;
        // }


    }

}