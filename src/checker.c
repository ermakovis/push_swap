/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcase <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/27 15:11:33 by tcase             #+#    #+#             */
/*   Updated: 2019/06/01 19:41:04 by tcase            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <time.h>
#include "../includes/push_swap.h"

int			timeout(int ms)
{
	int cur;
	int end;

	cur = clock() * 1000 / CLOCKS_PER_SEC;
	end = cur + ms;
	while (cur <= end)
		cur = clock() * 1000 / CLOCKS_PER_SEC;
	return (1);
}

static void	proc_options(int *argc, char ***argv, int *opt)
{
	char **tmp;

	tmp = *argv;
	if (ft_strnequ("-v", tmp[1], 2))
	{
		*argc = *argc - 1;
		*argv = &tmp[1];
		*opt = 1;
	}
	if (ft_strnequ("-c", tmp[1], 2))
	{
		*argc = *argc - 1;
		*argv = &tmp[1];
		*opt = 2;
	}
}

static void	show_debug(t_stk *stk_a, t_stk *stk_b, int size, int opt)
{
	int		size_a;
	int		size_b;
	int		i;
	int		j;

	size_a = get_stk_size(stk_a);
	size_b = get_stk_size(stk_b);
	ft_printf("+---stk_a----+----stk_b---+\n");
	while (size--)
	{
		if (size < size_a)
		{
			stk_a->sorted ? ft_printf("|\x1b[32m") : ft_printf("|\x1b[31m");
			ft_printf("%10d  ", stk_a->num);
			stk_a = stk_a->next;
			ft_printf("\x1b[0m");
		}
		else
			ft_printf("|%10s  ", " ");
		if (size < size_b && ft_printf("|\x1b[31m%10d  \x1b[0m|\n", stk_b->num))
			stk_b = stk_b->next;
		else
			ft_printf("|%10s  |\n", " ");
	}
	ft_printf("+------------+------------+\n");
}

void		proc_commands(t_stk *stk_a, t_stk *stk_b, int opt)
{
	char	*line;
	int		size;

	size = get_stk_size(stk_a);
	index_stk(stk_a, size);
	while ((get_next_line(0, &line)))
	{
		mark_stk(stk_a, size);
		if (!(check_command(line, &stk_a, &stk_b)))
			clean_stk(stk_a, stk_b, -1, "Error");
		if (opt >= 1 && ft_printf("%s\n", line))
			show_debug(stk_a, stk_b, size, opt);
		if (opt == 2 && timeout(500))
			ft_printf("\033[%dF", size + 3);
		ft_memdel((void**)&line);
	}
	if (opt == 2 && ft_printf("Finish\n"))
		show_debug(stk_a, stk_b, size, opt);
}

int			main(int argc, char **argv)
{
	t_stk	*stk_a;
	t_stk	*stk_b;
	int		opt;

	opt = 0;
	stk_a = NULL;
	stk_b = NULL;
	proc_options(&argc, &argv, &opt);
	fill_stk(&stk_a, argc, argv);
	proc_commands(stk_a, stk_b, opt);
	(!stk_b && check_sort(stk_a)) ? ft_putendl("OK") : ft_putendl("KO");
	clean_stk(stk_a, stk_b, 0, "All fine");
	return (0);
}
