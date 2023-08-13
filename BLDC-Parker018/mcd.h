/*
 * mcd.h
 *
 *  Created on: 18 maj 2023
 *      Author: student
 */

#ifndef MCD_H_
#define MCD_H_

struct mc_donaldy{
    float output_a;
    float output_b;
    float output_c;

};

void mcd_calc(struct mc_donaldy *tp, float a, float b, float c);


#endif /* MCD_H_ */
