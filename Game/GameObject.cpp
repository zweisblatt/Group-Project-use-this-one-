#include "GameObject.hpp"
#include "TextureManager.hpp"

GameObject::GameObject(const char* texturesheet, int x, int y){
    objTexture = TextureManager::LoadTexture(texturesheet);
    xpos = x;
    ypos = y;
}

void GameObject::update(){
    
    xpos++;
    ypos++;
    
    srcRect.h = 570;
    srcRect.w = 570;
    srcRect.x = 0;
    srcRect.y = 0;
    
    destRect.x = xpos;
    destRect.y = ypos;
    destRect.w = srcRect.w/6;
    destRect.h = srcRect.h/6;
}

void GameObject::render(){
    SDL_RenderCopy(Game::renderer, objTexture, &srcRect, &destRect);
}
 
