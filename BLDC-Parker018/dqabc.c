/*
 * dqabc.c
 *
 *  Created on: 22 maj 2023
 *      Author: student
 */

#include "dqabc.h"
#include "math.h"

void trans_dq_abc_calc(struct dq_abc *trans, float d, float q, float fi){
    fi *= 4; // uwzglednienie biegunow
    trans->a = cos(fi) * d - sin(fi) * q;
    trans->b = cos(fi - (TWO_THIRD * M_PI)) * d - sin(fi - (TWO_THIRD * M_PI)) * q;
    trans->c = cos(fi + (TWO_THIRD * M_PI)) * d - sin(fi + (TWO_THIRD * M_PI)) * q;
}
