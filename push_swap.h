
#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "./libft/libft.h"

typedef struct s_stack
{
	int		*simplified_values;
	int		*values;
	int		print_flag;
	int		len;
	char	id;
}			t_stack;

typedef struct s_cost
{
	int		index;
	int		a;
	int		b;
	int		sum;
}			t_cost;

typedef struct s_movs
{
	int		a;
	int		b;
	int		ab;
}			t_movs;

//init stacks
char		**argv_stack(int argc, char **argv);
t_stack		init_stack_a(char **argv_stack);
t_stack		init_stack_b(t_stack stack_a);

//check 
void		int_error(void);
void		check_int_numbers(char **argv_stack);
long int	push_swap_atoi(const char *str);
void		check_dup_stack_a(t_stack stack_a);
int			lowest_nbr(t_stack stack_a);
t_stack		simplified_values(t_stack stack_a);

//movements
void		swap(t_stack stack);
void		swap_ab(t_stack stack_a, t_stack stack_b);
void		push(t_stack stack_a, t_stack stack_b);
void		rotate(t_stack stack);
void		rotate_ab(t_stack stack_a, t_stack stack_b);
void		rev_rotate(t_stack stack);
void		rev_rotate_ab(t_stack stack_a, t_stack stack_b);

//target
int			target_low_limit(int surface, t_stack stack);
int			target_high_limit(int surface, t_stack stack);
int			target_stack_index(int i, t_stack stack_a, t_stack stack_b);

//cost
int			move_rotate(int i, t_stack stack);
int			move_rev_rotate(int i, t_stack stack);
int			abs_value(int a);
int			select_move(int i, t_stack stack);
t_cost		move_cost_counter(int i, t_stack stack_a, t_stack stack_b);

//algorithm
t_stack		basic_algorithm(t_stack stack_a);
int			empty_array_check(t_stack stack);
void		push_to_stack_b(t_stack stack_a, t_stack stack_b);
void		move_values(t_stack stack_a, t_stack stack_b, t_cost move);
void		make_move(t_stack stack_a, t_stack stack_b, t_movs times);
void		sorting_stacks(t_stack stack_a, t_stack stack_b);
void		rearrange_stack(t_stack stack);

//extra
void		printfunction(t_stack stack_a, t_stack stack_b);

#endif
