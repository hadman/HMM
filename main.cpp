#include <iostream>
//todo спроси про static class, методы, аттрибуты; extern

#include "include/SDL2/SDL.h"
#include <windows.h>
#include <string>

SDL_Window *window = NULL;
SDL_Renderer *renderer = NULL;

const int SCREEN_WIDTH = 844;
const int SCREEN_HEIGHT = 475;

SDL_Texture *LoadImage(std::string file) // создание текстуры по изображению
{
    SDL_Surface *loadedImage = NULL;
    SDL_Texture *texture = NULL;
    loadedImage = SDL_LoadBMP(file.c_str());
    if (loadedImage != NULL) {
        texture = SDL_CreateTextureFromSurface(renderer, loadedImage);
        SDL_FreeSurface(loadedImage);
    }
    else
        std::cout << SDL_GetError() << std::endl;
    return texture;
}

void ApplySurface(int x, int y, SDL_Texture *tex, SDL_Renderer *rend) // рисование на рендере
{
    SDL_Rect pos;
    pos.x = x;
    pos.y = y;
    SDL_QueryTexture(tex, NULL, NULL, &pos.w, &pos.h);
    SDL_RenderCopy(rend, tex, NULL, &pos);
}

#include "map.h"
#include "creature.h"
#include "player.h"

#include "undead.h"
#include "warrior.h"
#include "doctor.h"
#include "archer.h"

#include "vampire.h"
#include "Tent_ambulance.h"
#include "elf.h"
#include "skeleton_archer.h"
#include "monk.h"
#include "the_game.h"

#include "id.h"
// генерация уникальных id

using namespace std;


int main(int argc, char *argv[]) {
    creature_ID ID; // уникальный номер
    map::make_map(5, 10); // карта



    if (SDL_Init(SDL_INIT_EVERYTHING) == -1) {
        std::cout << SDL_GetError() << std::endl;
        return 1;
    }
    window = SDL_CreateWindow("HMM", 800,
                              100, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
    if (window == NULL) {
        std::cout << SDL_GetError() << std::endl;
        return 2;
    }
    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED
                                              | SDL_RENDERER_PRESENTVSYNC);
    if (renderer == NULL) {
        std::cout << SDL_GetError() << std::endl;
        return 3;
    }

    player player1(1);
    player player2(2);

    Tent_ambulance tent(ID.get_id());
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

    skeleton_archer skelet1(ID.get_id());
    skeleton_archer skelet2(ID.get_id());

    monk monk1(ID.get_id());
    monk monk2(ID.get_id());

    elf elf1(ID.get_id());
    elf elf2(ID.get_id());

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

    player1.addCreature(&vamp);
    player1.addCreature(&skelet1);
    player1.addCreature(&tent);
    player1.addCreature(&monk1);
//    player1.addCreature(&vamp2);
//    player1.addCreature(&vamp3);
//    player1.addCreature(&vamp4);
//    player1.addCreature(&vamp5);
//    player1.addCreature(&vamp6);
//    player1.addCreature(&vamp7);
//    player1.addCreature(&vamp6);

    player2.addCreature(&vamp8);
    player2.addCreature(&skelet2);
    player2.addCreature(&monk2);
    player2.addCreature(&elf1);

    cout << "***********" << endl;


    player1.put_creatures_on_map(); // расстановка первого игрока на карте
    player2.put_creatures_on_map(); // расстановка второго игрока на карте

    the_game GAME(player1, player2);


    GAME.print_map();
    GAME.start(player1, player2, renderer);

    int pos[2];

    //cout << "what is in point? " << map::get_creature_ID(1, 1) << endl;




    map::destroy_map();

    // SDL TEST



    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();


    return 0;


}
