/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_rot.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcase <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/25 15:41:30 by tcase             #+#    #+#             */
/*   Updated: 2019/05/25 16:28:39 by tcase            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	ra(t_stk **stk_a, t_stk **stk_b, char **res)
{
	char *tmp;

	tmp = *res;
	rot_stk(stk_a);
	if (!(tmp = ft_strjoin(tmp, "ra\n")))
		clean_stk(*stk_a, *stk_b, -1, "Malloc Failed - ra");
	ft_memdel((void**)res);
	*res = tmp;
}

void	rb(t_stk **stk_a, t_stk **stk_b, char **res)
{
	char *tmp;

	tmp = *res;
	rot_stk(stk_b);
	if (!(tmp = ft_strjoin(tmp, "rb\n")))
		clean_stk(*stk_a, *stk_b, -1, "Malloc Failed - rb");
	ft_memdel((void**)res);
	*res = tmp;
}

void	rr(t_stk **stk_a, t_stk **stk_b, char **res)
{
	char *tmp;

	tmp = *res;
	rot_stk(stk_a);
	rot_stk(stk_b);
	if (!(tmp = ft_strjoin(tmp, "rr\n")))
		clean_stk(*stk_a, *stk_b, -1, "Malloc Failed - rr");
	ft_memdel((void**)res);
	*res = tmp;
}
