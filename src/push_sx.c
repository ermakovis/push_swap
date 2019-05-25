/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_sx.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcase <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/25 16:17:38 by tcase             #+#    #+#             */
/*   Updated: 2019/05/25 18:50:36 by tcase            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	sa(t_stk **stk_a, t_stk **stk_b, char **res)
{
	char *tmp;

	tmp = *res;
	swap_stk(stk_a);
	if (!(tmp = ft_strjoin(tmp, "sa\n")))
		clean_stk(*stk_a, *stk_b, -1, "Malloc Failed - ra");
	ft_memdel((void**)res);
	*res = tmp;
}

void	sb(t_stk **stk_a, t_stk **stk_b, char **res)
{
	char *tmp;

	tmp = *res;
	swap_stk(stk_b);
	if (!(tmp = ft_strjoin(tmp, "sb\n")))
		clean_stk(*stk_a, *stk_b, -1, "Malloc Failed - rb");
	ft_memdel((void**)res);
	*res = tmp;
}

void	ss(t_stk **stk_a, t_stk **stk_b, char **res)
{
	char *tmp;

	tmp = *res;
	swap_stk(stk_a);
	swap_stk(stk_b);
	if (!(tmp = ft_strjoin(tmp, "ss\n")))
		clean_stk(*stk_a, *stk_b, -1, "Malloc Failed - rr");
	ft_memdel((void**)res);
	*res = tmp;
}
