/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   comp_steps.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcase <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/26 14:11:26 by tcase             #+#    #+#             */
/*   Updated: 2019/05/26 16:22:39 by tcase            ###   ########.fr       */
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
	while (steps_a > 0)
	{
		moves->ra++;
		steps_a--;
	}
	while (steps_b > 0)
	{
		moves->rb++;
		steps_b--;
	}
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
		moves->rrr++;
		steps_a--;
		steps_b--;
	}
	while (steps_a > 0)
	{
		moves->rra++;
		steps_a--;
	}
	while (steps_b > 0)
	{
		moves->rrb++;
		steps_b--;
	}
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
	while (steps_a < 0)
	{
		steps_a++;
		moves->rra++;
	}
	while (steps_a > 0)
	{
		steps_a--;
		moves->ra++;
	}
	while (steps_b < 0)
	{
		steps_b++;
		moves->rrb++;
	}
	while (steps_b > 0)
	{
		steps_b--;
		moves->rb++;
	}
	moves->total = (moves->rb + moves->ra + moves->rra + moves->rrb);
	*bth = moves;
	return (1);
}

int		smallest_of_three(int num1, int num2, int num3)
{
	if (num1 < num2)
	{
		if (num1 < num3)
			return (num1);
		else
			return (num3);
	}
	else if (num2 < num3)
		return (num2);
	else
		return (num3);
	return (0);
}

static void		assign_shortest(t_moves *fwd, t_moves *bwd, t_moves *bth,\
		t_moves **moves)
{
	int		num;
	t_moves *tmp;

	num = smallest_of_three(fwd->total, bwd->total, bth->total);
	if (num == fwd->total)
	{
		ft_memdel((void**)&bwd);
		ft_memdel((void**)&bth);
		tmp = fwd;
	}
	else if (num == bwd->total)
	{
		ft_memdel((void**)&fwd);
		ft_memdel((void**)&bth);
		tmp = bwd;
	}
	else if (num == bth->total)
	{
		ft_memdel((void**)&fwd);
		ft_memdel((void**)&bwd);
		tmp = bth;
	}
	*moves == NULL ? (*moves = tmp) : ((*moves)->next = tmp);
}

int				comp_steps(int steps_a, int steps_b, t_st *st, t_moves **moves)
{
	t_moves	*fwd;
	t_moves	*bwd;
	t_moves	*bth;

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
	assign_shortest(fwd, bwd, bth, moves);
	//printf("forwrd  -- ttl-%d | rr-%d | ra-%d | rb-%d\n", fwd->total, fwd->rr, fwd->ra, fwd->rb);
	//printf("backwrd -- ttl-%d | rrr-%d | rra-%d | rrb-%d\n", bwd->total, bwd->rrr, bwd->rra, bwd->rrb);
	//printf("both    -- ttl-%d | ra-%d | rra-%d | rb-%d | rrb-%d\n", bth->total, bth->ra, bth->rra, bth->rb, bth->rrb);
	return (1);
}
