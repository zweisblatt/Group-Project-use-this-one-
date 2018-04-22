
#include "Game.hpp"
#include "TextureManager.hpp"
#include "Map.hpp"
#include "Components.hpp"





Map* map;
Manager manager;
SDL_Renderer* Game::renderer = nullptr;
auto& Player(manager.addEntity());


Game::Game(){
    
}
Game::~Game(){
    
}

void Game::init(const char *title, int xpos, int ypos, int width, int height, bool fullscreen){
    
    int flags=0;
    if (fullscreen){
        flags=SDL_WINDOW_FULLSCREEN;
    }
    
    if(SDL_Init(SDL_INIT_EVERYTHING)==0){
        std::cout<<"Subsystems Initialized..."<< std::endl;
        
        window = SDL_CreateWindow(title, xpos, ypos, width, height, flags);
        if(window){
            std::cout<<"Window created..."<<std::endl;
        }
        renderer=SDL_CreateRenderer(window, -1, 0);
        if(renderer){
            SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
            std::cout<<"Renderer Created..."<<std::endl;
        }
        
        isRunning=true;
    }
    
    else{
        isRunning=false;
    }
    
    //Player = new GameObject("/Users/oliverhodge/Desktop/Game/Assets/rocket1.png",0,0);
    //enemy = new GameObject("/Users/oliverhodge/Desktop/Game/Assets/rock.png", -100, -100);
    map = new Map();
    
    Player.addComponent<PositionComponent>();
    Player.addComponent<SpriteComponent>("/Users/oliverhodge/Desktop/Game/Assets/rocket1.png");
    
}

void Game::handleEvents(){
    
    SDL_Event event;
    SDL_PollEvent(&event);
    switch(event.type){
        case SDL_QUIT:
            isRunning=false;
            break;
            
        default:
            break;
    }
    
}

void Game::update(){
    
    manager.refresh();
    manager.update();
    
    if (Player.getComponent<PositionComponent>().x() > 100){
        Player.getComponent<SpriteComponent>().setTex("/Users/oliverhodge/Desktop/Game/Assets/rock.png");
    }

    
}

void Game::render(){
    
    SDL_RenderClear(renderer);
    map->drawMap();
    
    manager.draw();
    SDL_RenderPresent(renderer);
    
}

void Game::clean(){
    
    SDL_DestroyWindow(window);
    SDL_DestroyRenderer(renderer);
    SDL_Quit();
    std::cout<<"Game Cleaned..."<<std::endl;
    
    
}
