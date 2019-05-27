/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_back.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcase <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/27 14:54:58 by tcase             #+#    #+#             */
/*   Updated: 2019/05/27 15:02:32 by tcase            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static int		get_min_steps(t_stk **stk_a, t_stk **stk_b, t_st *st)
{
	t_stk	*tmp;
	t_stk	*cur;
	t_stk	*next;
	int		i;

	cur = *stk_a;
	i = 0;
	while (i < st->size_a)
	{
		cur->next != NULL ? (next = cur->next) : (next = *stk_a);
		if (cur->index == st->min && (*stk_b)->index < st->min)
			return (i);
		if (next->index == st->max && (*stk_b)->index > st->max)
			return (i);
		i++;
		if (cur->index < (*stk_b)->index && (*stk_b)->index < next->index)
			return (i);
		cur = next;
	}
	return (i);
}

static void	init_stats(t_stk **stk_a, t_stk **stk_b, t_st **st)
{
	t_st	*tmp;

	if (!(tmp = (t_st*)malloc(sizeof(t_st))))
		clean_stk(*stk_a, *stk_b, -1, "Malloc Failed - init stats");
	ft_bzero((void*)tmp, sizeof(t_st));
	tmp->min = get_min_index(stk_a);
	tmp->max = get_max_index(stk_a);
	tmp->size_a = get_stk_size(*stk_a);
	tmp->size_b = get_stk_size(*stk_b);
	*st = tmp;
}

static void	find_smallest_total(t_moves *moves, t_moves **srt)
{
	t_moves *tmp;
	int		min;
	int		i;

	i = 0;
	tmp = moves;
	min = INT_MAX;
	while (tmp)
	{
		if (min > tmp->total)
		{
			min = tmp->total;
			*srt = tmp;
		}
		tmp = tmp->next;
	}
}

static void	make_steps(t_stk **stk_a, t_stk **stk_b, t_moves *moves, char **res)
{
	t_moves		*tmp;

	find_smallest_total(moves, &tmp);
	while (tmp->rrr--)
		rrr(stk_a, stk_b, res);
	while (tmp->rra--)
		rra(stk_a, stk_b, res);
	while (tmp->rrb--)
		rrb(stk_a, stk_b, res);
	while (tmp->rr--)
		rr(stk_a, stk_b, res);
	while (tmp->ra--)
		ra(stk_a, stk_b, res);
	while (tmp->rb--)
		rb(stk_a, stk_b, res);
	pa(stk_a, stk_b, res);
	(*stk_a)->sorted = 1;
}

void	move_back(t_stk **stk_a, t_stk **stk_b, char **res)
{
	t_st	*st;
	t_stk	*tmp;
	t_moves	*moves;
	int		steps_a;
	int		steps_b;

	moves = NULL;
	if (!stk_b || !*stk_b)
		return ;
	init_stats(stk_a, stk_b, &st);
	tmp = *stk_b;
	steps_b = 0;
	while (tmp)
	{
		steps_a = get_min_steps(stk_a, &tmp, st);
		if(comp_steps(steps_a, steps_b, st, &moves) == -1)
			clean_stk(*stk_a, *stk_b, -1, "Steps calcs failed");;
		steps_b++;
		tmp = tmp->next;
	}
	make_steps(stk_a, stk_b, moves, res);
	clean_moves(moves, st);
	move_back(stk_a, stk_b, res);
}
