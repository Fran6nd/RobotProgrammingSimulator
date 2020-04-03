#ifndef RESOURCES_H
#define RESOURCES_H

#include <SDL2/SDL.h>

typedef struct ResourcesManager ResourcesManager;

struct ResourcesManager{
    SDL_Texture** images;
    int images_counter;
};

ResourcesManager resources_new_manager();
void resources_free(ResourcesManager *);
int resources_load_image(ResourcesManager *, SDL_Renderer *, char *, int);
SDL_Texture * resources_get_image(ResourcesManager *, int id);

#endif