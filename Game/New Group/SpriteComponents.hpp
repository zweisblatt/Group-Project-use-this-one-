#ifndef SpriteComponents_hpp
#define SpriteComponents_hpp
#include "Components.hpp"
#include "SDL2/SDL.h"

class SpriteComponent : public Component{
private:
    TransformComponent *transform;
    SDL_Texture *texture;
    SDL_Rect srcRect, destRect;
    
public:
    SpriteComponent() = default;
    SpriteComponent(const char* path){
        setTex(path);
    }
    
    void setTex(const char* path){
        texture = TextureManager::LoadTexture(path);
    }
    
    void init() override{
        
        transform = &entity->getComponent<TransformComponent>();
        
        srcRect.x = srcRect.y = 0;
        srcRect.w = srcRect.h = 570;
        destRect.w = destRect.h = 95;
    }
    void update() override{
        destRect.x = (int)transform->position.x;
        destRect.y = (int)transform->position.y;
    }
    void draw() override{
        TextureManager::draw(texture, srcRect, destRect);
    }
};
 
#endif
