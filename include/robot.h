#ifndef ROBOT_H
#define ROBOT_H

#include <SDL2/SDL.h>

#include "transform.h"

struct robot {
    struct Transform transform;
};
struct robot new_robot(Transform);
void draw_robot(SDL_Renderer *r, struct robot*);
void update_robot(struct robot*, int);

#endif