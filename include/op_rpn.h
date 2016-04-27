#ifndef OP_RPN_H
#define OP_RPN_H

/*
 *  op_rpn.h
 *  This file is part of hpsh.
 *  See hpsh.c for copyright or LICENSE for license information.
 */

/* RPN stack operations */

#define OPS_RPN 4

extern void op_rpn_clear(list_t *stack);
extern void op_rpn_drop(list_t *stack);
extern void op_rpn_swap(list_t *stack);
extern void op_rpn_dup(list_t *stack);

#endif
