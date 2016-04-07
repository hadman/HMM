#include <iostream>
#include "creature.h"

using namespace std;

int main() {

    creature monster;

    string inter;
    cout << "Enter command:" << endl;
    cin >> inter;
    while (inter != "!") {
        if (inter == "mv") {
            double x, y;

            cout << "Input x" << endl;
            cin >> x;

            cout << "Input y" << endl;
            cin >> y;


            if (!monster.move(x, y)) {//запрашиваем координаты, пока не будут введены подходящие

                cout << "Input x" << endl;
                cin >> x;

                cout << "Input y" << endl;
                cin >> y;
            }

            cout << "Enter command:" << endl;
            cin >> inter;

        }
    }
}