#ifndef OP_MATH_H
#define OP_MATH_H

/*
 *  op_math.h
 *  This file is part of hpsh.
 *  See hpsh.c for copyright or LICENSE for license information.
 */

/* math operations */

#define OPS_MATH 11

extern void op_add(list_t *stack);
extern void op_subtract(list_t *stack);
extern void op_multiply(list_t *stack);
extern void op_divide(list_t *stack);
extern void op_power(list_t *stack);
extern void op_modulo(list_t *stack);
extern void op_sine(list_t *stack);
extern void op_cosine(list_t *stack);
extern void op_tangent(list_t *stack);
extern void op_neg(list_t *stack);
extern void op_sqrt(list_t *stack);

#endif
