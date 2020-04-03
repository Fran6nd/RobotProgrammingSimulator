#include "robot.h"
#include "transform.h"
#include "vector.h"

SDL_Texture *tank_img;
SDL_Rect tank_rect = {0, 0, 50, 50};

void robot_load_resources(SDL_Renderer *r)
{
    SDL_Surface *img = SDL_LoadBMP("rsc/robot_009e3f.bmp");
    SDL_SetColorKey(img, 1, 0x009e3f);
    tank_img = SDL_CreateTextureFromSurface(r, img);
    SDL_FreeSurface(img);
}

struct Robot new_robot(Transform t){
    struct Robot r;
    r.transform = t;
    r.wheel_perimeter = 31.42;
    r.rps1 = 0;
    r.rps2 = 0;
    return r;
}
void robot_draw(SDL_Renderer *r, struct Robot*rb){
    tank_rect.x = rb->transform.position.x - 25;
    tank_rect.y = rb->transform.position.y - 25;
    SDL_Point center = {25, 25};

    SDL_RenderCopyEx(r, tank_img, NULL, &tank_rect, rb->transform.rotation - 90, &center, 0);
}
void robot_free_resources()
{
    SDL_DestroyTexture(tank_img);
}
void robot_update(struct Robot* r, double dt){
    vector d1, d2;
    d1.y = r->wheel_perimeter * dt * r->rps1;
    d2.y = r->wheel_perimeter * dt * r->rps2;
    d1.x = 5;
    d2.x = -5;
}
