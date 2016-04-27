#ifndef INTERPRETER_H
#define INTERPRETER_H

/*
 *  interpreter.h
 *  This file is part of hpsh.
 *  See hpsh.c for copyright or LICENSE for license information.
 */

/* lexer and interpreter */

struct _command {
	const char *token;
	const char *name;
	unsigned args; /* args required */
	void (*op)(list_t *); /* func ptr */
};

typedef struct _command cmd_t;

extern void lexer(char *input, list_t *stack);

#endif
