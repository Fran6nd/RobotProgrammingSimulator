#ifndef ROBOT_H
#define ROBOT_H

#include <SDL2/SDL.h>

#include "transform.h"
#include "vector.h"

struct Instruction{
    int m1, m2, dir1, dir2;
};
struct wheel{
    struct Transform transform;
    
    double rps;
};

struct Robot {
    struct Transform transform;
    double wheel_perimeter;
    struct Instruction instruction;
    double rps_r, rps_l;
    vector wheel_r, wheel_l;
};
struct Robot new_robot(Transform);
void robot_draw(SDL_Renderer *r, struct Robot*);
void robot_update(struct Robot*, double);
void load_resources(SDL_Renderer *r);
void free_resources();
#endif