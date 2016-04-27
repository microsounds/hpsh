#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "stack.h"
#include "interpreter.h"
#include "op_math.h"
#include "op_rpn.h"

/*
 *  interpreter.c
 *  This file is part of hpsh.
 *  See hpsh.c for copyright or LICENSE for license information.
 */

/* lexer and interpreter */

#define OPS_CLI 2

void op_cli_quit(list_t *stack);
void op_cli_help(list_t *stack);

#define SUPPORTED_COMMANDS OPS_MATH + OPS_RPN + OPS_CLI

static const cmd_t LOOKUP[SUPPORTED_COMMANDS] = {
	/* from op_math.c */
	{ .token = "+", .name = "ADD", .args = 2, .op = &op_add },
	{ .token = "-", .name = "SUB", .args = 2, .op = &op_subtract },
	{ .token = "*", .name = "MULT", .args = 2, .op = &op_multiply },
	{ .token = "/", .name = "DIV", .args = 2, .op = &op_divide },
	{ .token = "^", .name = "POWER", .args = 2, .op = &op_power },
	{ .token = "%", .name = "MODULO", .args = 2, .op = &op_modulo },
	{ .token = "sin", .name = "SINE", .args = 1, .op = &op_sine },
	{ .token = "cos", .name = "COSINE", .args = 1, .op = &op_cosine },
	{ .token = "tan", .name = "TANGENT", .args = 1, .op = &op_tangent },
	{ .token = "neg", .name = "NEG", .args = 1, .op = &op_neg },
	{ .token = "sqrt", .name = "SQRT", .args = 1, .op = &op_sqrt },
	/* from op_rpn.c */
	{ .token = "clear", .name = "CLEAR", .args = 0, .op = &op_rpn_clear },
	{ .token = "drop", .name = "DROP", .args = 1, .op = &op_rpn_drop },
	{ .token = "swap", .name = "SWAP", .args = 2, .op = &op_rpn_swap },
	{ .token = "dup", .name = "DUP", .args = 1, .op = &op_rpn_dup },
	/* from interpreter.c */
	{ .token = "quit", .name = "QUIT", .args = 0, .op = &op_cli_quit },
	{ .token = "help", .name = "HELP", .args = 0, .op = &op_cli_help },
};

void op_cli_quit(list_t *stack)
{
	stack_destroy(stack);
	exit(0);
}

void op_cli_help(list_t *stack)
{
	unsigned i;
	for (i = 0; i < SUPPORTED_COMMANDS; i++)
	{
		if (i == 0)
			fprintf(stderr, "Math Functions\n");
		if (i == OPS_MATH)
			fprintf(stderr, "RPN Functions\n");
		if (i == OPS_MATH + OPS_RPN)
			fprintf(stderr, "CLI Functions\n");
		const char *name = LOOKUP[i].name;
		const char *token = LOOKUP[i].token;
		unsigned args = LOOKUP[i].args;
		fprintf(stderr, "\t%s\t'%s'\tTakes %u operands.\n", name, token, args);
	}
}

void strip_newlines(char *str)
{
	size_t len = strlen(str);
	size_t i;
	for (i = 0; i < len; i++)
	{
		if (str[i] == '\n')
			str[i] = ' ';
	}
}

int is_digit(const char c)
{
	return (c >= '0' && c <= '9');
}

int interpreter(const char *token)
{
	int i;
	for (i = 0; i < SUPPORTED_COMMANDS; i++)
	{
		if (!strcmp(token, LOOKUP[i].token))
			return i;
	}
	return -1;
}

void lexer(char *input, list_t *stack)
{
	strip_newlines(input);
	char *tok = strtok(input, " ");
	while (tok != NULL)
	{
		/* if negative or positive value */
		if ((tok[0] == '-' && is_digit(tok[1]) || is_digit(tok[0])))
		{
			double val = atof(tok);
			stack_push(stack, val);
		}
		else /* maybe it's a command? */
		{
			int cmd = interpreter(tok);
			if (cmd >= 0)
			{
				if (stack->depth >= LOOKUP[cmd].args)
					LOOKUP[cmd].op(stack); /* execute func pointer */
				else
				{
					const char *name = LOOKUP[cmd].name;
					unsigned args = LOOKUP[cmd].args;
					fprintf(stderr, "[!] %s requires %u operands.\n", name, args);
				}
			}
			else
				fprintf(stderr, "[!] '%s' is not a valid token.\n", tok);
		}
		tok = strtok(NULL, " ");
	}
}
