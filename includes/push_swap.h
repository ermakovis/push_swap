/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcase <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/26 17:29:53 by tcase             #+#    #+#             */
/*   Updated: 2019/05/27 15:25:06 by tcase            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include "../libft/libft.h"
# include <stdio.h>
# include <stdlib.h>
# include <limits.h>

typedef struct			s_stk
{
	int					num;
	int					index;
	int					sorted;
	struct s_stk		*next;
}						t_stk;

typedef struct			s_st
{
	int					size_a;
	int					size_b;
	int					min;
	int					max;
}						t_st;

typedef struct			s_moves
{
	int					rra;
	int					rrb;
	int					rrr;
	int					ra;
	int					rb;
	int					rr;
	int					total;
	struct s_moves		*next;
}						t_moves;

/*
**	move_back.c
*/
void					move_back(t_stk **stk_a, t_stk **stk_b, char **res);


/*
**  move_unsorted.c
*/
void					move_unsorted(t_stk **stk_a, t_stk **stk_b,\
							char **res, int size);
/*
**  comp_steps.c
*/
int						comp_steps(int steps_a, int steps_b,\
							t_st *st, t_moves **moves);
/*
** mark_stk.c
*/
void					index_stk(t_stk *stk, int size);
int						get_sorted_count(t_stk *stk, t_stk *tstk, int size);
t_stk					*find_best_stk(t_stk *stk, int size);
void					mark_stk(t_stk *stk, int size);
/*
**  stk_functions.c
*/
void					add_num(t_stk **stk_start, int num);
int						get_min_index(t_stk **stk);
int						get_max_index(t_stk **stk);
int						get_stk_size(t_stk *stk);
void					get_stk(t_stk *stk);
/*
**  checks.c
*/
int						check_command(char *line, t_stk **stk_a, t_stk **stk_b);
int						check_num(char *str);
int						check_sort(t_stk *stk);
int						get_smallest(int num1, int num2, int num3);
/*
**  move_stk.c
*/
int						push_stk(t_stk **stk_dest, t_stk **stk_src);
int						swap_stk(t_stk **stk);
int						rot_stk(t_stk **stk);
int						revrot_stk(t_stk **stk);
/*
**  cleanup.c
*/
void					clean_stk(t_stk *stk_a, t_stk *stk_b,\
							int res, char *message);
void					clean_moves(t_moves *moves, t_st *st);
void					clean_split(char **num);
void					get_last_move(t_moves **moves, t_moves **new);
/*
**  push_sx.c, push_rot.c, push_rrot.c, push_push.c
*/
void					sa(t_stk **stk_a, t_stk **stk_b, char **res);
void					sb(t_stk **stk_a, t_stk **stk_b, char **res);
void					ss(t_stk **stk_a, t_stk **stk_b, char **res);
void					pa(t_stk **stk_a, t_stk **stk_b, char **res);
void					pb(t_stk **stk_a, t_stk **stk_b, char **res);
void					ra(t_stk **stk_a, t_stk **stk_b, char **res);
void					rb(t_stk **stk_a, t_stk **stk_b, char **res);
void					rr(t_stk **stk_a, t_stk **stk_b, char **res);
void					rra(t_stk **stk_a, t_stk **stk_b, char **res);
void					rrb(t_stk **stk_a, t_stk **stk_b, char **res);
void					rrr(t_stk **stk_a, t_stk **stk_b, char **res);
#endif
