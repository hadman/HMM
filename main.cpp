#include <iostream>
#include <sstream>

//todo спроси про static class, методы, аттрибуты; extern

#include "SDL.h"
#include "SDL_image.h"
#include "SDL_ttf.h"

#include <windows.h>
#include <string>

#include <cstdlib>
#include <ctime>

SDL_Window *window = NULL;
SDL_Renderer *renderer = NULL;

const int SCREEN_WIDTH = 850;
const int SCREEN_HEIGHT = 591+40; // 475

static std::string logs = " "; // логи консоли


//Globally used font
TTF_Font *gFont = NULL; // шрифт

SDL_Color textColor;

//SDL_Texture* mTexture;

//Image dimensions
        int mWidth;
        int mHeight;

//Rendered texture
//LTexture gTextTexture; // текстура

std::string intToStr(int i)
{
        std::string i_str;          // string which will contain the result

        std::ostringstream convert;   // stream used for the conversion

        convert << i;      // insert the textual representation of 'Number' in the characters in the stream

        i_str = convert.str(); // set 'Result' to the contents of the stream
        return i_str;
}


SDL_Texture* LoadImage(std::string file) // создание текстуры по изображению
{
    SDL_Surface *loadedImage = NULL;
    SDL_Texture *texture = NULL;
    file = "img/" + file;
    loadedImage = IMG_Load(file.c_str());
    if (loadedImage != NULL){
        texture = SDL_CreateTextureFromSurface(renderer, loadedImage);
        SDL_FreeSurface(loadedImage);
    }
    else
        std::cout << SDL_GetError() << std::endl;
    return texture;
}

bool loadFromRenderedText( std::string textureText, SDL_Color& textColor , TTF_Font *& gFont, int x, int y);

bool Print_Font(TTF_Font *& gFont, SDL_Color& textColor, std::string textureText, int x, int y, int size)
{
    //Loading success flag
    bool success = true;

    //Open the font
    gFont = TTF_OpenFont( "ttf/TIMCYR.TTF", size );
    //std::cout << "gFont = " << gFont << std::endl;
    if( gFont == NULL )
    {
        std::cout <<  "Failed to load lazy font! SDL_ttf Error: %s\n" << TTF_GetError() << std::endl;
        success = false;
    }
    else
    {
        //Render text

        SDL_Color textColor = { 255, 255, 255 };
        if( !loadFromRenderedText( textureText, textColor, gFont, x, y) )
        {
            //std::cout << "Failed to render text texture!\n" << std::endl;
            success = false;
        }
        //std::cout << "mTexture = " <<  mTexture << std::endl;
    }

    return success;
}

void ApplySurface(int x, int y, SDL_Texture *tex, SDL_Renderer *rend) // рисование на рендере
{
    SDL_Rect pos;

    int frameWidth;
    int frameHeight;

    int textureWidth;
    int textureHeight;

    SDL_QueryTexture(tex, NULL, NULL, &textureWidth, &textureHeight);

    frameWidth = textureWidth;
    frameHeight = textureHeight;

    pos.x = x;
    pos.y = y;
    pos.w = frameWidth;
    pos.h = frameHeight;

    SDL_RenderCopy(rend, tex, NULL, &pos);
}

void ApplySurface(int x, int y, SDL_Texture *tex, SDL_Renderer *rend, int playerNum) // рисование на рендере
{
    SDL_Rect pos;
    SDL_Rect cut;

    int frameWidth;
    int frameHeight;

    int textureWidth;
    int textureHeight;

    SDL_QueryTexture(tex, NULL, NULL, &textureWidth, &textureHeight);

    frameWidth = textureWidth/2;
    frameHeight = textureHeight;

    pos.x = x;
    pos.y = y;
    pos.w = frameWidth;
    pos.h = frameHeight;

    SDL_QueryTexture(tex, NULL, NULL, &textureWidth, &textureHeight);

    frameWidth = textureWidth/2;
    frameHeight = textureHeight;

    if(playerNum == 1)
        cut.x = 0;
    else
        cut.x = frameWidth;
    cut.y = 0;
    cut.w = frameWidth;
    cut.h = frameHeight;

    SDL_RenderCopy(rend, tex, &cut, &pos);
}

bool loadFromRenderedText( std::string textureText, SDL_Color& textColor , TTF_Font *& gFont, int x, int y)
{
    //Get rid of preexisting texture
    //free();

    //Render text surface
    SDL_Texture* mTexture;

    SDL_Surface* textSurface = TTF_RenderText_Solid( gFont, textureText.c_str(), textColor );
    //std::cout << "textSurface = " <<  textSurface << std::endl;
    if( textSurface == NULL )
    {
        std::cout << "Unable to render text surface! SDL_ttf Error: %s\n" <<  TTF_GetError() << std::endl;
    }
    else
    {
        //Create texture from surface pixels
        //std::cout << "mTexture = " <<  mTexture << std::endl;
        mTexture = SDL_CreateTextureFromSurface( renderer, textSurface );
        //std::cout << "mTexture = " <<  mTexture << std::endl;

        ApplySurface(x,y,mTexture,renderer);



        if( mTexture == NULL )
        {
             std::cout << "Unable to create texture from rendered text! SDL Error: %s\n" << SDL_GetError() << std::endl;
        }
        /*else
        {
            //Get image dimensions
            mWidth = textSurface->w;
            mHeight = textSurface->h;
        }*/

        //Get rid of old surface
        SDL_FreeSurface( textSurface );
    }

    //Return success
    return mTexture != NULL;
}

int generate_in(int a, int b) // генератор случаного числа от a до b
{
    if (b >= a)
    {
        //unsigned int tmp = 41;
        srand(time(0));
        int tmp = rand();
        std::cout << "URON = " << tmp << std::endl;
        tmp = tmp % (b - a  + 1);
        std::cout << "a + tmp = " << a + tmp << std::endl;
        return a + tmp;
    }
    return 0;
}

#include "map.h"
#include "creature.h"


#include "undead.h"
#include "warrior.h"
#include "doctor.h"
#include "archer.h"

#include "vampire.h"
#include "Tent_ambulance.h"
#include "elf.h"
#include "skeleton_archer.h"
#include "monk.h"

#include "id.h"
#include "player.h"
#include "the_game.h"
// генерация уникальных id

using namespace std;


int main(int argc, char *argv[]) {
    map::make_map(5, 10); // карта



    if (SDL_Init(SDL_INIT_EVERYTHING) == -1){
        std::cout << SDL_GetError() << std::endl;
        return 1;
    }
    if (TTF_Init() < 0)
    {
      cout << "Error: " << TTF_GetError() << endl;
    };
    window = SDL_CreateWindow("HMM", SDL_WINDOWPOS_CENTERED,
                              SDL_WINDOWPOS_CENTERED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
    if (window == NULL){
        std::cout << SDL_GetError() << std::endl;
        return 2;
    }
    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED
                                              | SDL_RENDERER_PRESENTVSYNC);
    if (renderer == NULL){
        std::cout << SDL_GetError() << std::endl;
        return 3;
    }

    //TTF_font * font = TTF_OpenFont("TIMCYR.ttf",10);
    //SDL_Color color = {144, 77, 255, 255};






   player player1(1);
   player player2(2);

   cout << "***********" << endl;

   cout << "***********" << endl;

   //SDL_RenderClear( renderer );

    //Render current frame

    //cout << "mTexture = " << mTexture << endl;
    //cout << "gFont = " << gFont << endl;
    //Print_Font(gFont, textColor, "IGOR", 30, 40);
    //cout << "gFont = " << gFont << endl;
    //loadFromRenderedText( "Igor", textColor, gFont, mTexture, renderer );
    //cout << "mTexture = " << mTexture << endl;

    //ApplySurface(0,0,mTexture,renderer);

    //Update screen
    //SDL_RenderPresent( renderer );

    //SDL_Delay(3000);



    player1.make_army(); // выбор игроком армии
    player2.make_army();

   player1.put_creatures_on_map(); // расстановка первого игрока на карте
   player2.put_creatures_on_map(); // расстановка второго игрока на карте

    the_game GAME(player1, player2);


   //GAME.print_map();

   GAME.start(player1, player2,renderer);

   int pos[2];

   //cout << "what is in point? " << map::get_creature_ID(1, 1) << endl;




    map::destroy_map();

    // SDL TEST

    //Free loaded images
    //gTextTexture.free();

    TTF_CloseFont( gFont );
    gFont = NULL;
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);

    TTF_Quit();
    IMG_Quit();

    SDL_Quit();




    return 0;


}
