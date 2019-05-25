/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_rrot.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcase <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/25 15:54:09 by tcase             #+#    #+#             */
/*   Updated: 2019/05/25 16:28:40 by tcase            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	rra(t_stk **stk_a, t_stk **stk_b, char **res)
{
	char *tmp;

	tmp = *res;
	revrot_stk(stk_a);
	if (!(tmp = ft_strjoin(tmp, "rra\n")))
		clean_stk(*stk_a, *stk_b, -1, "Malloc Failed - rra");
	ft_memdel((void**)res);
	*res = tmp;
}

void	rrb(t_stk **stk_a, t_stk **stk_b, char **res)
{
	char *tmp;

	tmp = *res;
	revrot_stk(stk_b);
	if (!(tmp = ft_strjoin(tmp, "rrb\n")))
		clean_stk(*stk_a, *stk_b, -1, "Malloc Failed - rrb");
	ft_memdel((void**)res);
	*res = tmp;
}

void	rrr(t_stk **stk_a, t_stk **stk_b, char **res)
{
	char *tmp;

	tmp = *res;
	revrot_stk(stk_a);
	revrot_stk(stk_b);
	if (!(tmp = ft_strjoin(tmp, "rrr\n")))
		clean_stk(*stk_a, *stk_b, -1, "Malloc Failed - rrr");
	ft_memdel((void**)res);
	*res = tmp;
}
