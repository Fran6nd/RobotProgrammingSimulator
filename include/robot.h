#ifndef ROBOT_H
#define ROBOT_H

#include <SDL2/SDL.h>

#include "transform.h"

struct Robot {
    struct Transform transform;
};
struct Instruction{
    int m1, m2, dir1, dir2;
};
struct Robot new_robot(Transform);
void draw_robot(SDL_Renderer *r, struct Robot*);
void update_robot(struct Robot*, struct Instruction, int);

#endif