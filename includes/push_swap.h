#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include "../libft/libft.h"
# include <stdio.h>
# include <stdlib.h>
# include <limits.h>

typedef struct          s_stk
{
    int                 num;
	int					index;
	int					sorted;
    struct s_stk        *next;
}                       t_stk;

void	mark_stk(t_stk *stk, int size);
void	index_stk(t_stk *stk, int size);
int		get_sorted_count(t_stk *stk, t_stk *tstk, int size);
t_stk	*find_best_stk(t_stk *stk, int size);
int		check_sort(t_stk *stk);
int		check_command(char *line, t_stk **stk_a, t_stk **stk_b);
int     check_num(char *str);
int		get_stk_size(t_stk *stk);
void    get_stk(t_stk *stk);
void    add_num(t_stk **stk_start, int num);
void    clean_stk(t_stk *stk_a, t_stk *stk_b, int res, char *message);

void	move_unsorted(t_stk **stk_a, t_stk **stk_b, char **res, int size);

int		push_stk(t_stk **stk_dest, t_stk **stk_src);
int	    swap_stk(t_stk **stk);
int		rot_stk(t_stk **stk);
int		revrot_stk(t_stk **stk);

void    sa(t_stk **stk_a, t_stk **stk_b, char **res);
void    sb(t_stk **stk_a, t_stk **stk_b, char **res);
void    ss(t_stk **stk_a, t_stk **stk_b, char **res);
void    pa(t_stk **stk_a, t_stk **stk_b, char **res);
void    pb(t_stk **stk_a, t_stk **stk_b, char **res);
void    ra(t_stk **stk_a, t_stk **stk_b, char **res);
void    rb(t_stk **stk_a, t_stk **stk_b, char **res);
void    rr(t_stk **stk_a, t_stk **stk_b, char **res);
void    rra(t_stk **stk_a, t_stk **stk_b, char **res);
void    rrb(t_stk **stk_a, t_stk **stk_b, char **res);
void    rrr(t_stk **stk_a, t_stk **stk_b, char **res);
#endif
