#ifndef ROBOT_H
#define ROBOT_H

#include <SDL2/SDL.h>

#include "transform.h"

struct Instruction{
    int m1, m2, dir1, dir2;
};

struct Robot {
    struct Transform transform;
    double wheel_perimeter;
    struct Instruction instruction;
    double rps1, rps2;
};
struct Robot new_robot(Transform);
void draw_robot(SDL_Renderer *r, struct Robot*);
void update_robot(struct Robot*, double);
void load_resources(SDL_Renderer *r);
void free_resources();
#endif