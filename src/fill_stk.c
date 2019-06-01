/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_stk.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcase <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/01 11:54:04 by tcase             #+#    #+#             */
/*   Updated: 2019/06/01 19:43:41 by tcase            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static long		ft_push_atoi(const char *str)
{
	size_t			i;
	int				sign;
	long long int	nb;

	i = 0;
	sign = 1;
	nb = 0;
	while (str[i] == '\n' || str[i] == '\t' || str[i] == '\r' || \
				str[i] == '\v' || str[i] == '\f' || str[i] == ' ')
		i++;
	if (str[i] == '+')
		i++;
	else if (str[i] == '-')
	{
		sign = -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		nb = nb * 10 + (str[i] - '0');
		i++;
	}
	return (nb * sign);
}

static void		fill_str(t_stk **stk_a, char *str)
{
	char	**num;
	int		i;
	long	nb;

	num = ft_strsplit(str, ' ');
	i = 0;
	while (num[i])
	{
		if (!(check_num(num[i])))
			clean_stk(*stk_a, NULL, -1, "Error");
		nb = ft_push_atoi(num[i]);
		if (nb < INT_MIN || nb > INT_MAX)
			clean_stk(*stk_a, NULL, -1, "Error");
		add_num(stk_a, (int)nb);
		i++;
	}
	if (check_dup(stk_a) == -1)
		clean_stk(*stk_a, NULL, -1, "Error");
	clean_split(num);
}

static void		fill_num(t_stk **stk_a, char **argv)
{
	int		i;
	long	nb;

	i = 0;
	while (argv[++i])
	{
		if (!(check_num(argv[i])))
			clean_stk(*stk_a, NULL, -1, "Error");
		nb = ft_push_atoi(argv[i]);
		if (nb < INT_MIN || nb > INT_MAX)
			clean_stk(*stk_a, NULL, -1, "Error");
		add_num(stk_a, (int)nb);
	}
	if (check_dup(stk_a) == -1)
		clean_stk(*stk_a, NULL, -1, "Error");
}

int				fill_stk(t_stk **stk_a, int argc, char **argv)
{
	if (argc < 2)
		exit(-1);
	else if (argc == 2)
		fill_str(stk_a, argv[1]);
	else
		fill_num(stk_a, argv);
	return (1);
}
