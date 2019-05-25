#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include "../libft/libft.h"
# include <stdio.h>
# include <stdlib.h>

typedef struct          s_stk
{
    int                 num;
    struct s_stk        *next;
}                       t_stk;

int		check_sort(t_stk *stk);
int		check_command(char *line, t_stk **stk_a, t_stk **stk_b);
int     check_num(char *str);
void    clean_stk(t_stk *stk_a, t_stk *stk_b, int res, char *message);
int		push_stk(t_stk **stk_dest, t_stk **stk_src);
int	    swap_stk(t_stk **stk);
int		rot_stk(t_stk **stk);
int		revrot_stk(t_stk **stk);

#endif
