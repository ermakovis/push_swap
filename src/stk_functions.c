/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stk_functions.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcase <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/25 11:58:57 by tcase             #+#    #+#             */
/*   Updated: 2019/05/25 20:16:19 by tcase            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void    get_stk(t_stk *stk)
{
	while (stk)
	{
		printf("%10d%10d%10d\n", stk->num, stk->index, stk->sorted);
		stk = stk->next;
	}
}

int		get_stk_size(t_stk *stk)
{
	int		i;
	t_stk	*tmp;

	if (!stk)
		return (0);
	i = 0;
	tmp = stk;
	while (tmp)
	{
		tmp = tmp->next;
		i++;
	}
	return(i);
}

void    add_num(t_stk **stk_start, int num)
{
	t_stk   *stk;
	t_stk   *stk_tmp;

	stk_tmp = *stk_start;
	if (!(stk = (t_stk*)malloc(sizeof(t_stk))))
		clean_stk(*stk_start, NULL, -1, "Malloc failed");
	stk->num = num;
	stk->index = -1;
	stk->sorted = 0;
	stk->next = NULL;
	if (stk_tmp == NULL)
		*stk_start = stk;
	else 
	{
		while (stk_tmp->next)
			stk_tmp = stk_tmp->next;
		stk_tmp->next = stk;
	}
}
