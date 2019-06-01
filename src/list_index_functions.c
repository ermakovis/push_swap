/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_index_functions.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcase <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/01 11:19:08 by tcase             #+#    #+#             */
/*   Updated: 2019/06/01 19:42:26 by tcase            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int		get_index_first_sorted(t_stk **stk_a)
{
	t_stk	*tmp;

	tmp = *stk_a;
	while (tmp)
	{
		if (tmp->sorted)
			return (tmp->index);
		tmp = tmp->next;
	}
	return (-1);
}

int		get_index_last_sorted(t_stk **stk_a)
{
	t_stk	*tmp;
	int		last;

	last = -1;
	tmp = *stk_a;
	while (tmp)
	{
		if (tmp->sorted)
			last = tmp->index;
		tmp = tmp->next;
	}
	return (last);
}

int		get_min_index(t_stk **stk)
{
	t_stk	*tmp;
	int		min;

	min = INT_MAX;
	tmp = *stk;
	while (tmp)
	{
		if (min > tmp->index)
			min = tmp->index;
		tmp = tmp->next;
	}
	return (min);
}

int		get_max_index(t_stk **stk)
{
	t_stk	*tmp;
	int		max;

	max = INT_MIN;
	tmp = *stk;
	while (tmp)
	{
		if (max < tmp->index)
			max = tmp->index;
		tmp = tmp->next;
	}
	return (max);
}

int		get_smallest(int num1, int num2, int num3)
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
	return (num1);
}
