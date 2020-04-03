#include "robot.h"
#include "transform.h"
#include "vector.h"
#include "resources.h"

int img_id;

void load_resources(SDL_Renderer *r)
{
    img_id = resources_load_image(r, "rsc/robot_009e3f.bmp", 0x009e3f);
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
    SDL_Rect tank_rect = {0, 0, 50, 50};
    tank_rect.x = rb->transform.position.x - 25;
    tank_rect.y = rb->transform.position.y - 25;
    SDL_Point center = {25, 25};

    SDL_RenderCopyEx(r, resources_get_image(img_id), NULL, &tank_rect, rb->transform.rotation - 90, &center, 0);
}
void robot_update(struct Robot* r, double dt){
    vector d1, d2;
    d1.y = r->wheel_perimeter * dt * r->rps1;
    d2.y = r->wheel_perimeter * dt * r->rps2;
    d1.x = 5;
    d2.x = -5;
}
