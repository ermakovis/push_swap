/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcase <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/25 10:52:24 by tcase             #+#    #+#             */
/*   Updated: 2019/05/25 21:59:03 by tcase            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	move_back(t_stk **stk_a, t_stk **stk_b, char **res, int size)
{
	get_min_steps(stk_a, stk_b, res, size);
}

int		main(int argc, char **argv)
{
	int     i;
	t_stk   *stk_a;
	t_stk   *stk_b;
	char	*res;

	i = 0;
	stk_a = NULL;
	stk_b = NULL;
	if (!(res = ft_strnew(1)))
		exit (-1);
	while (++i < argc)
	{     
		if (!(check_num(argv[i])))
			clean_stk(stk_a, NULL, -1, "Wrong input");
		add_num(&stk_a, ft_atoi(argv[i])); 
	}
	i = get_stk_size(stk_a);
	index_stk(stk_a, i);
	mark_stk(stk_a, i);
	move_unsorted(&stk_a, &stk_b, &res, i);
	move_back(%stk_a, &stk_b, &res, i);
	printf("%s", res);
	get_stk(stk_a);
	clean_stk(stk_a, stk_b, 0, "All fine");
}
