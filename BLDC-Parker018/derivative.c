#include "derivative.h"
#include "math.h"

void derivative_calc(struct derivative *dv, float angle){
    float delta_angle = angle - dv->angle_1;
    if (delta_angle <=  - M_PI)
        delta_angle += 2 * M_PI;
    else if(delta_angle >= M_PI)
        delta_angle -= 2 * M_PI;


    dv->output = 10*(delta_angle)/dv->delta_t;
    dv->angle_1 = angle;
}

void derivative_init(struct derivative *dv, float delta_t){
    dv->output = 0;
    dv->angle_1 = 0;
    dv->delta_t = delta_t;
}
