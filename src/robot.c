#include "robot.h"
#include "transform.h"

SDL_Texture *tank_img;
SDL_Rect tank_rect = {0, 0, 50, 50};

void load_resources(SDL_Renderer *r)
{
    SDL_Surface *img = SDL_LoadBMP("rsc/robot_009e3f.bmp");
    SDL_SetColorKey(img, 1, 0x009e3f);
    tank_img = SDL_CreateTextureFromSurface(r, img);
    SDL_FreeSurface(img);
}

struct Robot new_robot(Transform t){
    struct Robot r;
    r.transform = t;
    return r;
}
void draw_robot(SDL_Renderer *r, struct Robot*rb){
    tank_rect.x = rb->transform.position.x - 25;
    tank_rect.y = rb->transform.position.y - 25;
    SDL_Point center = {25, 25};

    SDL_RenderCopyEx(r, tank_img, NULL, &tank_rect, rb->transform.rotation - 90, &center, 0);
}
void free_resources()
{
    SDL_DestroyTexture(tank_img);
}
