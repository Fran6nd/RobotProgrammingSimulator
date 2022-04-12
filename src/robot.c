#include "robot.h"
#include "transform.h"
#include "vector.h"
#include "resources_manager.h"

int img_id;

void load_resources(SDL_Renderer *r)
{
    img_id = resources_load_image(r, "rsc/robot_009e3f.bmp", 0x009e3f);
}

struct Robot new_robot(Transform t)
{
    struct Robot r;
    r.transform = t;
    r.wheel_perimeter = 31.42;
    r.rps_r = 0;
    r.rps_l = 0;
    r.wheel_l.x = 20;
    r.wheel_l.y = 0;
    r.wheel_r.x = -20;
    r.wheel_r.y = 0;
    return r;
}
void robot_draw(SDL_Renderer *r, struct Robot *rb)
{
    SDL_Rect tank_rect = {0, 0, 50, 50};
    tank_rect.x = rb->transform.position.x - 25;
    tank_rect.y = rb->transform.position.y - 25;
    SDL_Point center = {25, 25};

    SDL_RenderCopyEx(r, resources_get_image(img_id), NULL, &tank_rect, rb->transform.rotation - 90, &center, 0);
    SDL_SetRenderDrawColor(r, 0, 0, 0, 0);
    //SDL_RenderDrawLine()
}
void robot_update(struct Robot *r, double dt)
{
    vector d1, d2;
    d1.y = r->wheel_perimeter * dt * r->rps_r;
    d2.y = r->wheel_perimeter * dt * r->rps_l;
    d1.x = 20;
    d2.x = -20;
    double dx = d1.x - d2.x;
    double dy = d1.y - d2.y;
    

}
