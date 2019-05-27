/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   comp_steps.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcase <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/26 14:11:26 by tcase             #+#    #+#             */
/*   Updated: 2019/05/27 15:27:16 by tcase            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static int		comp_fwd(int steps_a, int steps_b, t_st *st, t_moves **fwd)
{
	t_moves *moves;

	moves = NULL;
	if (!(moves = (t_moves*)malloc(sizeof(t_moves))))
		return (-1);
	ft_bzero(moves, sizeof(t_moves));
	while (steps_a > 0 && steps_b > 0)
	{
		moves->rr++;
		steps_a--;
		steps_b--;
	}
	while (steps_a > 0 && steps_a--)
		moves->ra++;
	while (steps_b > 0 && steps_b--)
		moves->rb++;
	moves->total = (moves->rr + moves->ra + moves->rb);
	*fwd = moves;
	return (1);
}

static int		comp_bwd(int steps_a, int steps_b, t_st *st, t_moves **bwd)
{
	t_moves *moves;

	moves = NULL;
	if (!(moves = (t_moves*)malloc(sizeof(t_moves))))
		return (-1);
	ft_bzero(moves, sizeof(t_moves));
	steps_a = ft_abs(steps_a - st->size_a);
	steps_b = ft_abs(steps_b - st->size_b);
	while (steps_a > 0 && steps_b > 0)
	{
		steps_a--;
		steps_b--;
		moves->rrr++;
	}
	while (steps_a > 0 && steps_a--)
		moves->rra++;
	while (steps_b > 0 && steps_b--)
		moves->rrb++;
	moves->total = (moves->rrr + moves->rra + moves->rrb);
	*bwd = moves;
	return (1);
}

static int		comp_bth(int steps_a, int steps_b, t_st *st, t_moves **bth)
{
	t_moves *moves;

	moves = NULL;
	if (!(moves = (t_moves*)malloc(sizeof(t_moves))))
		return (-1);
	ft_bzero(moves, sizeof(t_moves));
	steps_a <= ft_abs(steps_a - st->size_a) ? steps_a :\
		(steps_a = steps_a - st->size_a);
	steps_b <= ft_abs(steps_b - st->size_b) ? steps_b :\
		(steps_b = steps_b - st->size_b);
	while (steps_a < 0 && steps_a++)
		moves->rra++;
	while (steps_a > 0 && steps_a--)
		moves->ra++;
	while (steps_b < 0 && steps_b++)
		moves->rrb++;
	while (steps_b > 0 && steps_b--)
		moves->rb++;
	moves->total = (moves->rb + moves->ra + moves->rra + moves->rrb);
	*bth = moves;
	return (1);
}

static void		assign_shortest(t_moves *fwd, t_moves *bwd, t_moves *bth,\
		t_moves **moves)
{
	int		num;
	t_moves *tmp;

	num = get_smallest(fwd->total, bwd->total, bth->total);
	if (num == fwd->total && (tmp = fwd))
	{
		ft_memdel((void**)&bwd);
		ft_memdel((void**)&bth);
	}
	else if (num == bwd->total && (tmp = bwd))
	{
		ft_memdel((void**)&fwd);
		ft_memdel((void**)&bth);
	}
	else if (num == bth->total && (tmp = bth))
	{
		ft_memdel((void**)&fwd);
		ft_memdel((void**)&bwd);
	}
	*moves = tmp;
}

int				comp_steps(int steps_a, int steps_b, t_st *st, t_moves **moves)
{
	t_moves	*fwd;
	t_moves	*bwd;
	t_moves	*bth;
	t_moves *tmp;

	fwd = NULL;
	bwd = NULL;
	bth = NULL;
	if (comp_fwd(steps_a, steps_b, st, &fwd) == -1)
		return (-1);
	if (comp_bwd(steps_a, steps_b, st, &bwd) == -1)
	{
		ft_memdel((void**)&fwd);
		return (-1);
	}
	if (comp_bth(steps_a, steps_b, st, &bth) == -1)
	{
		ft_memdel((void**)&fwd);
		ft_memdel((void**)&bwd);
		return (-1);
	}
	assign_shortest(fwd, bwd, bth, &tmp);
	get_last_move(moves, &tmp);
	return (1);
}
