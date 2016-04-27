#include <stdio.h>
#include <stdlib.h>

#include "stack.h"

/*
 *  stack.c
 *  This file is part of hpsh.
 *  See hpsh.c for copyright or LICENSE for license information.
 */

/* linked list stack */

void stack_display(list_t *stack)
{
	/* replay linked list stack in reverse */
	node_t *current = stack->head;
	double *state = (double *) malloc(sizeof(double) * stack->depth);
	size_t i = 0;
	while (current != NULL)
	{
		state[i++] = current->data;
		current = current->next;
	}
	while (i--)
		fprintf(stdout, "%zu: %g\n", i + 1, state[i]);
	free(state);
}

void stack_push(list_t *stack, double data)
{
	node_t *node = (node_t *) malloc(sizeof(node_t));
	node->data = data;
	node->next = stack->head;
	stack->head = node;
	stack->depth++;
}

double stack_pop(list_t *stack)
{
	double data = 0.0;
	if (stack->depth > 0)
	{
		node_t *pruned = stack->head;
		stack->head = pruned->next;
		stack->depth--;
		data = pruned->data;
		free(pruned);
	}
	return data;
}

void stack_init(list_t *stack)
{
	stack->head = NULL;
	stack->depth = 0;
}

void stack_destroy(list_t *stack)
{
	while (stack->head)
		stack_pop(stack);
}
