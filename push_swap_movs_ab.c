#include "push_swap.h"

void	swap_ab(t_stack stack_a, t_stack stack_b)
{
	stack_a.print_flag = 1;
	stack_b.print_flag = 1;
	swap(stack_a);
	swap(stack_b);
	stack_a.print_flag = 0;
	stack_b.print_flag = 0;
	ft_putstr_fd("ss\n", 1);

}

void	rotate_ab(t_stack stack_a, t_stack stack_b)
{
	stack_a.print_flag = 1;
	stack_b.print_flag = 1;
	rotate(stack_a);
	rotate(stack_b);
	stack_a.print_flag = 0;
	stack_b.print_flag = 0;
	ft_putstr_fd("rr\n", 1);
}

void	rev_rotate_ab(t_stack stack_a, t_stack stack_b)
{
	stack_a.print_flag = 1;
	stack_b.print_flag = 1;
	rev_rotate(stack_a);
	rev_rotate(stack_b);
	stack_a.print_flag = 0;
	stack_b.print_flag = 0;
	ft_putstr_fd("rrr\n", 1);
}
