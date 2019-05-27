/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcase <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/25 10:52:24 by tcase             #+#    #+#             */
/*   Updated: 2019/05/27 14:06:34 by tcase            ###   ########.fr       */
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

void	find_smallest_total(t_moves *moves, t_moves **srt)
{
	t_moves *tmp;
	int		min;
	int		i;

	i = 0;
	tmp = moves;
	min = INT_MAX;
	while (tmp)
	{
		i++;
		tmp = tmp->next;
	}
//	printf("moves size = %d\n", i);
	tmp = moves;
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

void	make_steps(t_stk **stk_a, t_stk **stk_b, t_moves *moves, char **res)
{
	t_moves		*tmp;

//	printf("-------------------CHOOSING BEST-----------------------\n");
	find_smallest_total(moves, &tmp);
//	printf("choosen - ttl-%d |ra-%d|rb-%drr-%d|rra-%d|rrb-%d|rrr-%d\n",\
			tmp->total, tmp->ra, tmp->rb, tmp->rr,\
			tmp->rra, tmp->rrb, tmp->rrr);
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
//	printf("-------------------CHOOSING MOVE-----------------------\n");
	while (tmp)
	{
		steps_a = get_min_steps(stk_a, &tmp, st);
		if(comp_steps(steps_a, steps_b, st, &moves) == -1)
			clean_stk(*stk_a, *stk_b, -1, "Steps calcs failed");;
		steps_b++;
		tmp = tmp->next;
	}
	make_steps(stk_a, stk_b, moves, res);
//	printf("---------------------FINISH--------------------------\n");
	clean_moves(moves, st);
	move_back(stk_a, stk_b, res);
}

void	align_start(t_stk **stk_a, t_stk **stk_b, char **res, int size)
{
	int		i;

	if ((*stk_a)->index < ft_abs((*stk_a)->index - size))
		i = (*stk_a)->index;
	else
		i = (*stk_a)->index - size;
	while (i < 0 && i++)
		ra(stk_a, stk_b, res);
	while (i > 0 && i--)
		rra(stk_a, stk_b, res);
}
void	fill_str(t_stk **stk_a, char *str)
{
	char	**num;
	int		i;

	num = ft_strsplit(str, ' ');
	i =	0;
	while (num[i])
	{
		if (!(check_num(num[i])))
			clean_stk(*stk_a, NULL, -1, "Fill Failed");
		add_num(stk_a, ft_atoi(num[i]));
		i++;
	}
	clean_split(num);
}

void	fill_num(t_stk **stk_a, int argc, char **argv)
{
	int		i;

	i = 0;
	while (++i < argc)
	{
		if (!(check_num(argv[i])))
			clean_stk(*stk_a, NULL, -1, "Fill Failed");
		add_num(stk_a, ft_atoi(argv[i]));
	}
}
int		main(int argc, char **argv)
{
	t_stk   *stk_a;
	t_stk   *stk_b;
	char	*res;
	int     i;

	i = 0;
	stk_a = NULL;
	stk_b = NULL;
	if (argc < 2)
		return (-1);
	else if (argc == 2)
		fill_str(&stk_a, argv[1]);
	else 
		fill_num(&stk_a, argc, argv);
	i = get_stk_size(stk_a);
	index_stk(stk_a, i);
	mark_stk(stk_a, i);
//	get_stk(stk_a);
	if (!(res = ft_strnew(1)))
		clean_stk(stk_a, NULL, -1, "Failed Malloc - res");
	move_unsorted(&stk_a, &stk_b, &res, i);
	move_back(&stk_a, &stk_b, &res);
	align_start(&stk_a, &stk_b, &res, i);
	printf("%s", res);
//	printf(" -----------stk_a-------------\n");
//	get_stk(stk_a);
//	printf(" -----------stk_b-------------\n");
//	get_stk(stk_b);
//	printf(" -----------------------------\n");
	ft_memdel((void**)&res);
	clean_stk(stk_a, stk_b, 0, "All fine");
}
