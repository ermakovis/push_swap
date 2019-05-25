#include "../includes/push_swap.h"

void    add_num(t_stk **stk_start, int num)
{
	t_stk   *stk;
	t_stk   *stk_tmp;

	stk_tmp = *stk_start;
	if (!(stk = (t_stk*)malloc(sizeof(t_stk))))
		clean_stk(*stk_start, NULL, -1, "Malloc failed");
	stk->num = num;
	stk->next = NULL;
	if (stk_tmp == NULL)
		*stk_start = stk;
	else 
	{
		while (stk_tmp->next)
			stk_tmp = stk_tmp->next;
		stk_tmp->next = stk;
	}
}

void    get_stk(t_stk *stk)
{
	while (stk)
	{
		printf("%d\n", stk->num);
		stk = stk->next;
	}
}

int     main(int argc, char **argv)
{
	int     i;
	char    *line;
	t_stk   *stk_a;
	t_stk   *stk_b;

	i = 0;
	stk_a = NULL;
	stk_b = NULL;
	while (++i < argc)
	{     
		if (!(check_num(argv[i])))
			clean_stk(stk_a, NULL, -1, "Wrong input");
		add_num(&stk_a, ft_atoi(argv[i])); 
	}
	while ((get_next_line(0, &line)) && ft_strcmp("", line))
	{
		if (!(check_command(line, &stk_a, &stk_b)))
			clean_stk(stk_a, stk_b, -1, "Wrong command");
		get_stk(stk_a);
		printf("\n");
		get_stk(stk_b);
		ft_memdel((void**)&line);
	}
	(!stk_b && check_sort(stk_a)) ? ft_putendl("OK") : ft_putendl("KO");
	clean_stk(stk_a, stk_b, 0, "All fine");
	return (0);
}
