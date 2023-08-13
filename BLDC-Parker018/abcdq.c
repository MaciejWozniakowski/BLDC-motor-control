/*
 * abcdq.c
 *
 *  Created on: 22 maj 2023
 *      Author: student
 */
#include "abcdq.h"
#include "math.h"


void trans_abc_dq_calc(struct abc_dq *transabcdq, float a, float b, float c, float fi){
    fi *=4;
    transabcdq->id = TWO_THIRD * (cos(fi) * a + cos(fi - (TWO_THIRD * M_PI)) * b + cos(fi + (TWO_THIRD * M_PI)) * c);
    transabcdq->iq = TWO_THIRD * (-sin(fi) * a - sin(fi - (TWO_THIRD * M_PI)) * b - sin(fi + (TWO_THIRD * M_PI)) * c);
}
