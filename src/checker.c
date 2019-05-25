#include "../includes/push_swap.h"

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
	i = get_stk_size(stk_a);
	index_stk(stk_a, i);
	while ((get_next_line(0, &line)) && ft_strcmp("", line))
	{
		if (!(check_command(line, &stk_a, &stk_b)))
			clean_stk(stk_a, stk_b, -1, "Wrong command");
		mark_stk(stk_a, i);
		printf("--------\n");
		printf("stk_a\n");
		get_stk(stk_a);
		printf("\n");
		printf("stk_b\n");
		get_stk(stk_b);
		ft_memdel((void**)&line);
	}
	(!stk_b && check_sort(stk_a)) ? ft_putendl("OK") : ft_putendl("KO");
	clean_stk(stk_a, stk_b, 0, "All fine");
	return (0);
}
