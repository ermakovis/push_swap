/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcase <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/25 10:52:24 by tcase             #+#    #+#             */
/*   Updated: 2019/05/26 16:19:59 by tcase            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int		get_min_steps(t_stk **stk_a, t_stk **stk_b, t_st *st)
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

void	calc_stats(t_stk **stk_a, t_stk **stk_b, t_st *st)
{
	st->min	= get_min_index(stk_a);
	st->max = get_max_index(stk_a);
	st->size_a = get_stk_size(*stk_a);
	st->size_b = get_stk_size(*stk_b);
}

void	make_steps(t_stk **stk_a, t_stk **stk_b, t_moves *moves, char **res)
{
	while (moves->rrr--)
		rrr(stk_a, stk_b, res);
	while (moves->rra--)
		rra(stk_a, stk_b, res);
	while (moves->rrb--)
		rrb(stk_a, stk_b, res);
	while (moves->rr--)
		rr(stk_a, stk_b, res);
	while (moves->ra--)
		ra(stk_a, stk_b, res);
	while (moves->rb--)
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
	if (!(st = (t_st*)malloc(sizeof(t_st))))
		clean_stk(*stk_a, *stk_b, -1, "Malloc Failed");
	ft_bzero((void*)st, sizeof(t_st));
	calc_stats(stk_a, stk_b, st);
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
	ft_memdel((void**)&moves);
	ft_memdel((void**)&st);
	move_back(stk_a, stk_b, res);
}

int		main(int argc, char **argv)
{
	int     i;
	t_stk   *stk_a;
	t_stk   *stk_b;
	char	*res;

	i = 0;
	stk_a = NULL;
	stk_b = NULL;
	if (!(res = ft_strnew(1)))
		exit (-1);
	while (++i < argc)
	{     
		if (!(check_num(argv[i])))
			clean_stk(stk_a, NULL, -1, "Wrong input");
		add_num(&stk_a, ft_atoi(argv[i])); 
	}
	i = get_stk_size(stk_a);
	index_stk(stk_a, i);
	mark_stk(stk_a, i);
	move_unsorted(&stk_a, &stk_b, &res, i);
	move_back(&stk_a, &stk_b, &res);
	printf("%s", res);
	printf(" -----------stk_a-------------\n");
	get_stk(stk_a);
	printf(" -----------stk_b-------------\n");
	get_stk(stk_b);
	printf(" -----------------------------\n");
	ft_memdel((void**)&res);
	clean_stk(stk_a, stk_b, 0, "All fine");
}
