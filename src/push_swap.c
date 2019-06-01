/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcase <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/25 10:52:24 by tcase             #+#    #+#             */
/*   Updated: 2019/06/01 19:44:38 by tcase            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

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

int		main(int argc, char **argv)
{
	t_stk	*stk_a;
	t_stk	*stk_b;
	char	*res;
	int		i;

	i = 0;
	stk_a = NULL;
	stk_b = NULL;
	fill_stk(&stk_a, argc, argv);
	i = get_stk_size(stk_a);
	index_stk(stk_a, i);
	mark_stk(stk_a, i);
	if (!(res = ft_strnew(1)))
		clean_stk(stk_a, NULL, -1, "Failed Malloc - res");
	move_unsorted(&stk_a, &stk_b, &res, i);
	move_back(&stk_a, &stk_b, &res);
	align_start(&stk_a, &stk_b, &res, i);
	ft_printf("%s", res);
	ft_memdel((void**)&res);
	clean_stk(stk_a, stk_b, 0, "All fine");
}
