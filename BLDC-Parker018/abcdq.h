/*
 * abcdq.h
 *
 *  Created on: 22 maj 2023
 *      Author: student
 */

#ifndef ABCDQ_H_
#define ABCDQ_H_

//#define __BSD_VISIBLE
#include <math.h>
#define TWO_THIRD 0.6666666667

struct abc_dq{

    float id;
    float iq;
};

void trans_abc_dq_calc(struct abc_dq *transabcdq, float a, float b, float c, float fi);


#endif /* ABCDQ_H_ */
