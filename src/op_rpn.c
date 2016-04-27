#include <stdlib.h>

#include "stack.h"

/*
 *  op_rpn.c
 *  This file is part of hpsh.
 *  See hpsh.c for copyright or LICENSE for license information.
 */

/* RPN stack operations */

void op_rpn_clear(list_t *stack)
{
	stack_destroy(stack);
}

void op_rpn_drop(list_t *stack)
{
	stack_pop(stack);
}

void op_rpn_swap(list_t *stack)
{
	double val1 = stack_pop(stack);
	double val2 = stack_pop(stack);
	stack_push(stack, val2);
	stack_push(stack, val1);
}

void op_rpn_dup(list_t *stack)
{
	stack_push(stack, stack->head->data);
}
