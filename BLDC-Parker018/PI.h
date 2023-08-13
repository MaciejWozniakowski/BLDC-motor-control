/*
 * PI.h
 *
 *  Created on: 22 maj 2023
 *      Author: student
 */

#ifndef PI_H_
#define PI_H_

struct PI{
    float x;
    float y;
    float y_1;
    float x_1;
    float Ts_PI;
    float Kr;
    float Ti;
    float integ;
    float final_output;
    float integ_1;
    float final_output_before;
    float max;
    float min;
};

void PIInit(struct PI *pi, float Ts, float Kr, float Ti, float max, float min);



void PICalc(struct PI *pi, float x, float feedback);


#endif /* PI_H_ */
