#include <iostream>

#include "creature.h"

#include "vampire.h"
#include "player.h"
#include "map.h"
#include "id.h" // генерация уникальных id

using namespace std;

int main() {
    creature_ID ID; // уникальный номер
    map MAP(5, 10);  // карта

    creature monster;
    player player1(1);
    player player2(2);

    vampire vamp(ID.get_id());
    vampire vamp2(ID.get_id());
    vampire vamp3(ID.get_id());
    vampire vamp4(ID.get_id());
    vampire vamp5(ID.get_id());
    vampire vamp6(ID.get_id());
    vampire vamp7(ID.get_id());

    vampire vamp8(ID.get_id());
    vampire vamp9(ID.get_id());
    vampire vamp10(ID.get_id());
    vampire vamp11(ID.get_id());

//    cout << "***********" << endl;
//
//    cout << "id = " << vamp.get_id() << endl;
//    cout << "id = " << vamp2.get_id() << endl;
//    cout << "id = " << vamp3.get_id() << endl;
//    cout << "id = " << vamp4.get_id() << endl;
//    cout << "id = " << vamp5.get_id() << endl;
//    cout << "id = " << vamp6.get_id() << endl;
//    cout << "id = " << vamp7.get_id() << endl;

//    cout << "id = " << vamp8.get_id() << endl;
//    cout << "id = " << vamp9.get_id() << endl;
//    cout << "id = " << vamp10.get_id() << endl;
//    cout << "id = " << vamp11.get_id() << endl;

    cout << "***********" << endl;


    player1.addCreature(vamp);
    player1.addCreature(vamp2);
    player1.addCreature(vamp3);
    player1.addCreature(vamp4);
    player1.addCreature(vamp5);
    player1.addCreature(vamp6);
    player1.addCreature(vamp7);

    player2.addCreature(vamp8);
    player2.addCreature(vamp9);
    player2.addCreature(vamp10);
    player2.addCreature(vamp11);

    cout << "***********" << endl;


    MAP.put_1_player(player1); // расстановка первого игрока на карте
    MAP.put_2_player(player2); // расстановка второго игрока на карте

    MAP.print_map();







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