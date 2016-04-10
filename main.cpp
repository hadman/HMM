#include <iostream>

#include "creature.h"

#include "vampire.h"
#include "player.h"
#include "id.h" // генерация уникальных id

using namespace std;

int main() {
    creature_ID ID; // уникальный номер

    creature monster;
    player player1(1);
    player player2(2);

    vampire vamp(ID.get_id());
    vampire vamp2(ID.get_id());
    vampire vamp3(ID.get_id());

    cout << "***********" << endl;

    cout << "id = " << vamp.get_id() << endl;
    cout << "id = " << vamp2.get_id() << endl;
    cout << "id = " << vamp3.get_id() << endl;

    cout << "***********" << endl;


    player1.addCreature(vamp);
    player1.addCreature(vamp2);
    player2.addCreature(vamp3);





//    double x, y;
//
//    cout << "Input x:";
//    cin >> x;
//
//    cout << "Input y:";
//    cin >> y;

//    if (x != 0 && y != 0) {
//
//        //if (!monster.move(x, y)) {//запрашиваем координаты, пока не будут введены подходящие
//
//            cout << "Input x:";
//            cin >> x;
//
//            cout << "Input y:";
//            cin >> y;
//        // }
//
//
//    }

}