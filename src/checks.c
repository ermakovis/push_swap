/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcase <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/24 20:53:55 by tcase             #+#    #+#             */
/*   Updated: 2019/05/26 11:46:46 by tcase            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int		check_sort(t_stk *stk)
{
	t_stk	*tmp;

	tmp = stk;
	while (tmp->next)
	{
		if (tmp->num > tmp->next->num)
			return (0);
		tmp = tmp->next;
	}
	return (1);
}

int     check_num(char *str)
{
    int     i;

    i = 0;
    while (str[i])
    {
        if (!(ft_isdigit(str[i])) && str[i] != '-')
            return (0);
        i++;
    }
    return (1);
}

int		check_command(char *line, t_stk **stk_a, t_stk **stk_b)
{
	if (ft_strnequ("sa", line, 3))
		return (swap_stk(stk_a));
	if (ft_strnequ("sb", line, 3))
		return (swap_stk(stk_b));
	if (ft_strnequ("ss", line, 3))
	{
		swap_stk(stk_a);
		return (swap_stk(stk_b));
	}
	if (ft_strnequ("pa", line, 3))
		return (push_stk(stk_a, stk_b));
	if (ft_strnequ("pb", line, 3))
		return (push_stk(stk_b, stk_a));
	if (ft_strnequ("ra", line, 3))
		return (rot_stk(stk_a));
	if (ft_strnequ("rb", line, 3))
		return (rot_stk(stk_b));
	if (ft_strnequ("rr", line, 3))
	{
		rot_stk(stk_a);
		return (rot_stk(stk_b));
	}
	if (ft_strnequ("rra", line, 4))
		return (revrot_stk(stk_a));
	if (ft_strnequ("rrb", line, 4))
		return (revrot_stk(stk_b));
	if (ft_strnequ("rrr", line, 4))
	{
		revrot_stk(stk_a);
		return (revrot_stk(stk_b));
	}
	return (0);
}

