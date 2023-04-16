#include "push_swap.h"

void	swap(t_stack stack)
{
	int	i;
	int	nbr;

	i = 0;
	nbr = 0;
	while (i < stack.len)
	{
		if (stack.simplified_values[i] > 0)
			nbr++;
		i++;
	}
	if (nbr > 1)
	{
		nbr = stack.simplified_values[0];
		stack.simplified_values[0] = stack.simplified_values[1];
		stack.simplified_values[1] = nbr;
	}
	if (stack.print_flag != 1)
	{
		ft_putstr_fd("s", 1);
		ft_putchar_fd(stack.id, 1);
		ft_putstr_fd("\n", 1);
	}
}

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

void	push(t_stack stack_a, t_stack stack_b)
{
	int	i;
	int	j;
	int	nbr;

	i = 0;
	j = 0;
	while (i < stack_a.len && stack_b.simplified_values[i] == 0)
		i++;
	if (i != stack_a.len)
	{
		while (j < stack_a.len && stack_a.simplified_values[j + 1] == 0)
			j++;
		if (j == stack_a.len)
			j--;
		nbr = stack_b.simplified_values[i];
		stack_b.simplified_values[i] = stack_a.simplified_values[j];
		stack_a.simplified_values[j] = nbr;
		ft_putstr_fd("p", 1);
		ft_putchar_fd(stack_a.id, 1);
		ft_putstr_fd("\n", 1);
	}
}

void	rotate(t_stack stack)
{
	int	i;
	int	j;
	int	nbr;
	int	save;

	i = 0;
	while (i < stack.len && stack.simplified_values[i] == 0)
		i++;
	if (i < stack.len - 1)
	{
		j = (stack.len - 1);
		nbr = stack.simplified_values[j];
		stack.simplified_values[j] = stack.simplified_values[i];
		while (j > i)
		{
			save = stack.simplified_values[j - 1];
			stack.simplified_values[j - 1] = nbr;
			nbr = save;
			j--;
		}
	}
	if (stack.print_flag != 1)
	{
		ft_putstr_fd("r", 1);
		ft_putchar_fd(stack.id, 1);
		ft_putstr_fd("\n", 1);
	}
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
