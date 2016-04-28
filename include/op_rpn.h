#ifndef OP_RPN_H
#define OP_RPN_H

/*
 *  op_rpn.h
 *  This file is part of hpsh.
 *  See hpsh.c for copyright or LICENSE for license information.
 */

/* RPN stack operations */

#define OPS_RPN 15

extern void op_rpn_clear(list_t *stack);
extern void op_rpn_drop(list_t *stack);
extern void op_rpn_drop2(list_t *stack);
extern void op_rpn_dropn(list_t *stack);
extern void op_rpn_swap(list_t *stack);
extern void op_rpn_pick(list_t *stack);
extern void op_rpn_unpic(list_t *stack);
extern void op_rpn_dup(list_t *stack);
extern void op_rpn_dup2(list_t *stack);
extern void op_rpn_dupn(list_t *stack);
extern void op_rpn_over(list_t *stack);
extern void op_rpn_pick3(list_t *stack);
extern void op_rpn_rot(list_t *stack);
extern void op_rpn_unrot(list_t *stack);
extern void op_rpn_depth(list_t *stack);

#endif
