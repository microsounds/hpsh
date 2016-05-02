#include <stdio.h>
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

void op_rpn_drop2(list_t *stack)
{
	stack_pop(stack);
	stack_pop(stack);
}

void op_rpn_dropn(list_t *stack)
{
	/* drop n stack levels if n is positive and doesn't exceed stack depth */
	long long drop = (long long) stack_pop(stack);
	if (drop > 0 && drop <= stack->depth)
	{
		long long i;
		for (i = 0; i < drop; i++)
			stack_pop(stack);
	}
	else
		fprintf(stderr, "[!] Cannot DROP %lld arguments. (Have %zu)\n", drop, stack->depth);

}

void op_rpn_swap(list_t *stack)
{
	double val1 = stack_pop(stack);
	double val2 = stack_pop(stack);
	stack_push(stack, val2);
	stack_push(stack, val1);
}

void op_rpn_pick(list_t *stack)
{
	/* dup selected level if positive and doesn't exceed stack depth */
	long long pick = (long long) stack_pop(stack);
	if (pick > 0 && pick <= stack->depth)
	{
		unsigned lvl = 1; /* traverse stack */
		node_t *current = stack->head;
		while (lvl++ < pick)
			current = current->next;
		stack_push(stack, current->data);
	}
	else
		fprintf(stderr, "[!] Stack level %lld does not exist.\n", pick);
}

void op_rpn_unpic(list_t *stack)
{
	/* drop selected level + 1 if positive and doesn't exceed stack depth */
	long long drop = (long long) stack_pop(stack) + 1;
	if (drop > 0 && drop <= stack->depth)
	{
		long long i; /* store stack in buffer */
		unsigned depth = stack->depth;
		double *tmp = (double *) malloc(sizeof(double) * depth);
		for (i = 0; i < depth; i++)
			tmp[i] = stack_pop(stack);
		while (i--) /* replay buffer back to stack */
		{
			if (i + 1  == drop) /* drop this one */
				continue;
			else
				stack_push(stack, tmp[i]);
		}
		free(tmp);
	}
	else
		fprintf(stderr, "[!] Stack level %lld does not exist.\n", drop);
}

void op_rpn_dup(list_t *stack)
{
	stack_push(stack, stack->head->data);
}

void op_rpn_dup2(list_t *stack)
{
	double val1 = stack->head->data;
	double val2 = stack->head->next->data;
	stack_push(stack, val2);
	stack_push(stack, val1);
}

void op_rpn_dupn(list_t *stack)
{
	/* dup n stack levels if n is positive and doesn't exceed stack depth */
	long long dup = (long long) stack_pop(stack);
	if (dup > 0 && dup <= stack->depth)
	{
		long long i, j, k;
		double *tmp = (double *) malloc(sizeof(double) * dup);
		for (i = 0; i < dup; i++)
			tmp[i] = stack_pop(stack);
		for (j = 0; j < 2; j++) /* replay tmp buffer twice to DUP */
		{
			k = i;
			while (k--)
				stack_push(stack, tmp[k]);
		}
		free(tmp);
	}
	else
		fprintf(stderr, "[!] Cannot DUP %lld arguments. (Have %zu)\n", dup, stack->depth);
}

void op_rpn_over(list_t *stack)
{
	stack_push(stack, stack->head->next->data);
}

void op_rpn_pick3(list_t *stack)
{
	/* or you could push 3 and call op_rpn_pick() */
	stack_push(stack, stack->head->next->next->data);
}

void op_rpn_rot(list_t *stack)
{
	/* stack lvl 3 is now 1, 1 and 2 shift up by 1 */
	double val1 = stack_pop(stack);
	double val2 = stack_pop(stack);
	double val3 = stack_pop(stack);
	stack_push(stack, val2);
	stack_push(stack, val1);
	stack_push(stack, val3);
}

void op_rpn_unrot(list_t *stack)
{
	/* stack lvl 1 is now 3, 3 and 2 shift down by 1 */
	double val1 = stack_pop(stack);
	double val2 = stack_pop(stack);
	double val3 = stack_pop(stack);
	stack_push(stack, val1);
	stack_push(stack, val3);
	stack_push(stack, val2);
}

void op_rpn_depth(list_t *stack)
{
	/* push stack depth as a value on the stack */
	stack_push(stack, stack->depth);
}
