#ifndef STACK_H
#define STACK_H

/*
 *  stack.h
 *  This file is part of hpsh.
 *  See hpsh.c for copyright or LICENSE for license information.
 */

/* linked list stack */

struct _node {
	double data;
	struct _node *next;
};

struct _list {
	struct _node *head;
	size_t depth;
};

typedef struct _node node_t;
typedef struct _list list_t;

extern void stack_display(list_t *stack);
extern void stack_push(list_t *stack, double data);
extern double stack_pop(list_t *stack);
extern void stack_init(list_t *stack);
extern void stack_destroy(list_t *stack);

#endif
