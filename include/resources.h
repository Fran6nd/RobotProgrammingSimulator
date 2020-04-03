#ifndef RESOURCES_H
#define RESOURCES_H

#include <SDL2/SDL.h>

typedef struct ResourceImage ResourceImage;
typedef struct ResourcesManager ResourcesManager;
struct ResourceImage{
    SDL_Texture * image;
    SDL_Rect rect;
};

struct ResourcesManager{
    struct ResourceImage* images;
    int images_counter;
};

ResourcesManager resources_new_manager();
void resources_free(ResourcesManager *);
int resources_load_image(SDL_Renderer *, ResourcesManager *, char *, int);
ResourceImage resources_get_image(ResourcesManager *, int id);

#endif