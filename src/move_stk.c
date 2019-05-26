/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_stk.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcase <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/24 20:12:10 by tcase             #+#    #+#             */
/*   Updated: 2019/05/26 11:46:36 by tcase            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int    swap_stk(t_stk **stk)
{
    t_stk   *tmp;
    t_stk   *tmp2;

    if (!*stk || !((*stk)->next))
        return (1);
    tmp = *stk;
    tmp2 = (*stk)->next;
    tmp->next = tmp2->next;
    tmp2->next = tmp;
    *stk = tmp2;
	return (1);
}

int		revrot_stk(t_stk **stk)
{
	t_stk	*tmp;
	t_stk	*tmp2;

	if (!*stk || !((*stk)->next))
		return (1);
	tmp = *stk;
	while (tmp->next)
	{
		tmp2 = tmp;
		tmp = tmp->next;
	}
	tmp2->next = NULL;
	tmp->next = (*stk);
	*stk = tmp;
	return (1);
}

int		rot_stk(t_stk **stk)
{
	t_stk	*tmp;

	if (!*stk || !((*stk)->next))
		return (1);
	tmp = *stk;
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = *stk;
	*stk = (*stk)->next;
	tmp->next->next = NULL;
	return (1);
}

int		push_stk(t_stk **stk_dest, t_stk **stk_src)
{
	t_stk	*tmp;

	if (!stk_src || !*stk_src)
		return (1);
	tmp = *stk_src;
	(*stk_src) = (*stk_src)->next;
	if (*stk_dest == NULL)
	{
		*stk_dest = tmp;
		(*stk_dest)->next = NULL;
	}
	else
	{
		tmp->next = *stk_dest;
		*stk_dest = tmp;
	}
	return (1);
}

void    clean_stk(t_stk *stk_a, t_stk *stk_b, int res, char *message)
{
    t_stk   *tmp;

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
	{
		ft_putstr_fd(message, 2);
		ft_putchar('\n');
	}
    exit (res);
}
