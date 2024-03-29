/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleanup.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcase <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/26 17:51:24 by tcase             #+#    #+#             */
/*   Updated: 2019/06/01 19:21:43 by tcase            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	get_last_move(t_moves **moves, t_moves **new)
{
	t_moves		*tmp;

	tmp = *moves;
	if (*moves == NULL)
		*moves = *new;
	else
	{
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = *new;
	}
}

void	clean_stk(t_stk *stk_a, t_stk *stk_b, int res, char *message)
{
	t_stk	*tmp;

	tmp = NULL;
	while (stk_a)
	{
		tmp = stk_a;
		stk_a = stk_a->next;
		ft_memdel((void**)&(tmp));
	}
	while (stk_b)
	{
		tmp = stk_b;
		stk_b = stk_b->next;
		ft_memdel((void**)&(tmp));
	}
	if (res != 0)
		ft_dprintf(2, "%s\n", message);
	exit(res);
}

void	clean_moves(t_moves *moves, t_st *st)
{
	t_moves *tmp;

	tmp = NULL;
	while (moves)
	{
		tmp = moves;
		moves = moves->next;
		ft_memdel((void**)&tmp);
	}
	ft_memdel((void**)&st);
}

void	clean_split(char **num)
{
	int		i;

	i = 0;
	while (num[i])
	{
		ft_memdel((void**)&num[i]);
		i++;
	}
	free(num);
}
