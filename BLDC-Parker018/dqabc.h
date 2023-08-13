/*
 * dqabc.h
 *
 *  Created on: 22 maj 2023
 *      Author: student
 */

#ifndef DQABC_H_
#define DQABC_H_
#define __BSD_VISIBLE
#include <math.h>
#define TWO_THIRD 0.66667

struct dq_abc{

    float a;
    float b;
    float c;
};

void trans_dq_abc_calc(struct dq_abc *trans, float d, float q, float fi);

#endif /* DQABC_H_ */
