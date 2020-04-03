#include "robot.h"
#include "transform.h"
struct Robot new_robot(Transform t){
    struct Robot r;
    r.transform = t;
    return r;

}