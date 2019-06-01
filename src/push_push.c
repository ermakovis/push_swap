/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_push.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcase <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/25 16:12:07 by tcase             #+#    #+#             */
/*   Updated: 2019/06/01 11:41:47 by tcase            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	pa(t_stk **stk_a, t_stk **stk_b, char **res)
{
	char *tmp;

	tmp = *res;
	push_stk(stk_a, stk_b);
	if (!(*res = ft_strjoin(*res, "pa\n")))
		clean_stk(*stk_a, *stk_b, -1, "Malloc Failed - pa");
	ft_memdel((void**)&tmp);
}

void	pb(t_stk **stk_a, t_stk **stk_b, char **res)
{
	char *tmp;

	tmp = *res;
	push_stk(stk_b, stk_a);
	if (!(*res = ft_strjoin(*res, "pb\n")))
		clean_stk(*stk_a, *stk_b, -1, "Malloc Failed - pb");
	ft_memdel((void**)&tmp);
}
