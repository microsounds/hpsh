#include <stdlib.h>
#include <math.h>

#include "stack.h"
#include "op_math.h"

/*
 *  op_math.c
 *  This file is part of hpsh.
 *  See hpsh.c for copyright or LICENSE for license information.
 */

/* math operations */

void op_add(list_t *stack)
{
	double rval = stack_pop(stack);
	double lval = stack_pop(stack);
	stack_push(stack, lval + rval);

}

void op_subtract(list_t *stack)
{
	double rval = stack_pop(stack);
	double lval = stack_pop(stack);
	stack_push(stack, lval - rval);
}

void op_multiply(list_t *stack)
{
	double rval = stack_pop(stack);
	double lval = stack_pop(stack);
	stack_push(stack, lval * rval);
}

void op_divide(list_t *stack)
{
	double rval = stack_pop(stack);
	double lval = stack_pop(stack);
	stack_push(stack, lval / rval);
}

void op_power(list_t *stack)
{
	double rval = stack_pop(stack);
	double lval = stack_pop(stack);
	stack_push(stack, pow(lval, rval));
}

void op_modulo(list_t *stack)
{
	long long rval = stack_pop(stack);
	long long lval = stack_pop(stack);
	stack_push(stack, lval % rval);
}

void op_sine(list_t *stack)
{
	double val = stack_pop(stack);
	stack_push(stack, sin(val));
}

void op_cosine(list_t *stack)
{
	double val = stack_pop(stack);
	stack_push(stack, cos(val));
}

void op_tangent(list_t *stack)
{
	double val = stack_pop(stack);
	stack_push(stack, tan(val));
}

void op_neg(list_t *stack)
{
	double val = stack_pop(stack);
	stack_push(stack, val * -1);
}

void op_sqrt(list_t *stack)
{
	double val = stack_pop(stack);
	stack_push(stack, sqrt(val));
}

