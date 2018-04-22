#ifndef Game_hpp
#define Game_hpp
#include <iostream>
#include "SDL2/SDL.h"
#include "SDL2_image/SDL_image.h"



class Game{
    
public:
    Game();
    ~Game();
    
    void init(const char* title, int xpos, int ypos, int width, int height, bool fullscreen);
    void handleEvents();
    void update();
    void render();
    void clean();
    static SDL_Renderer *renderer;
    
    bool running(){return isRunning;}
private:
    int cnt;
    bool isRunning;
    SDL_Window *window;
    
    
    
};

#endif /* Game_hpp */
