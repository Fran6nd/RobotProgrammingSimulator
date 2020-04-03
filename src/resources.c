#include "resources.h"

ResourcesManager resources_new_manager()
{
    ResourcesManager rm = {.images = NULL, .images_counter = 0};
    return rm;
}
void resources_free(ResourcesManager *rm)
{
    int i;
    for (i = 0; i < rm->images_counter; i++)
    {
        SDL_DestroyTexture(rm->images[i]);
    }
    free(rm->images);
    rm->images_counter = 0;
}
int resources_load_image(ResourcesManager *rm, SDL_Renderer *r, char *path, int color_key)
{
    SDL_Surface *img = SDL_LoadBMP(path);
    if (color_key != -1)
        SDL_SetColorKey(img, 1, color_key);
    rm->images_counter++;
    if (rm->images_counter == 1)
    {
        rm->images = malloc(sizeof(rm->images));
    }
    else
    {
        rm->images = realloc(rm->images, sizeof(rm->images) * rm->images_counter);
    }
    rm->images[rm->images_counter - 1] =SDL_CreateTextureFromSurface(r, img);
    SDL_FreeSurface(img);
    return rm->images_counter - 1;
}
SDL_Texture * resources_get_image(ResourcesManager * rm, int id){
    return rm->images[id];
}