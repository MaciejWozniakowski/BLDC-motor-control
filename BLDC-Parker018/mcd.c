/*
 * mcd.c
 *
 *  Created on: 18 maj 2023
 *      Author: student
 */
#include "mcd.h"
#include "math.h"

float maks (float a, float b, float c)
{
    if(a > b && a > c)
    return a;
    else if (b > a && b > c)
    return b;
    else return c;
}
float minim (float a, float b, float c)
{
    if(a < b && a < c)
    return a;
    else if (b < a && b < c)
    return b;
    else return c;
}

void mcd_calc(struct mc_donaldy *tp, float a, float b, float c){
    float maksimum = 0;
    maksimum = maks(a, b, c);
    float minimum = 0;
    minimum = minim(a, b, c);
    float summed_a = 0;
    summed_a = (maksimum + minimum)*(-0.5) + a;
    float summed_b = 0;
    summed_b = (maksimum + minimum)*(-0.5) + b;
    float summed_c = 0;
    summed_c = (maksimum + minimum)*(-0.5) + c;
    tp->output_a = summed_a;
    tp->output_b = summed_b;
    tp->output_c = summed_c;
}



