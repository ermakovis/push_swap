#include "../includes/push_swap.h"
#include "../libft/libft.h"

void    clean_stacks(t_stk *stk_a, t_stk *stk_b, int res)
{
    t_stk   *tmp;

    while (stk_a)
    {
       tmp = stk_a;
       stk_a = stk_a->next;
       ft_memdel((void**)&(stk_a));
    }
    while (stk_b)
    {
       tmp = stk_b;
       stk_b = stk_b->next;
       ft_memdel((void**)&(stk_b));
    }
    exit (res);
}

int     check_num(char *str)
{
    int     i;

    i = 0;
    while (str[i])
    {
        if (!(ft_isdigit(str[i])))
            return (0);
        i++;
    }
    return (1);
}

void    add_num(t_stk **stk_start, int num)
{
    t_stk   *stk;
    t_stk   *stk_tmp;

    stk_tmp = *stk_start;
    if (!(stk = (t_stk*)malloc(sizeof(t_stk))))
        clean_stacks(*stk_start, NULL, -1);
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

void    swap_stk(t_stk **stk)
{
    t_stk   *tmp;
    t_stk   *tmp2;

    if (!*stk || !((*stk)->next))
        return ;
    tmp = *stk;
    tmp2 = (*stk)->next;
    tmp->next = tmp2->next;
    tmp2->next = tmp;
    *stk = tmp2;
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
            clean_stacks(stk_a, NULL, -1);
        add_num(&stk_a, ft_atoi(argv[i])); 
    }
    swap_stk(&stk_a);
    get_stk(stk_a);
    get_stk(stk_b);
    clean_stacks(stk_a, stk_b, 1);
    return (1);
}
