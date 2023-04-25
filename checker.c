#include "push_swap.h"

void	check_sort_result(t_stack stack_a)
{
	int	i;

	i = 0;
	while (i < stack_a.len - 1)
	{
		if (stack_a.simplified_values[i] < stack_a.simplified_values[i + 1])
			i++;
		else
			break ;
	}
	if (i == stack_a.len - 1)
		ft_putstr_fd("OK\n", 1);
	else
	{
		ft_putstr_fd("KO\n", 1);
		exit(EXIT_FAILURE);
	}
}

void	check_and_make_moves(t_stack stack_a, t_stack stack_b, char *output)
{
	if (ft_strncmp("sa\n", output, 3) == 0)
		swap(stack_a);
	else if (ft_strncmp("sb\n", output, 3) == 0)
		swap(stack_b);
	else if (ft_strncmp("ss\n", output, 3) == 0)
		swap_ab(stack_a, stack_b);
	else if (ft_strncmp("pa\n", output, 3) == 0)
		push(stack_a, stack_b);
	else if (ft_strncmp("pb\n", output, 3) == 0)
		push(stack_b, stack_a);
	else if (ft_strncmp("ra\n", output, 3) == 0)
		rotate(stack_a);
	else if (ft_strncmp("rb\n", output, 3) == 0)
		rotate(stack_b);
	else if (ft_strncmp("rr\n", output, 3) == 0)
		rotate_ab(stack_a, stack_b);
	else if (ft_strncmp("rra\n", output, 4) == 0)
		rev_rotate(stack_a);
	else if (ft_strncmp("rrb\n", output, 4) == 0)
		rev_rotate(stack_b);
	else if (ft_strncmp("rrr\n", output, 4) == 0)
		rev_rotate_ab(stack_a, stack_b);
	else
		int_error();
}

int	main(int argc, char **argv)
{
	t_stack	stack_a;
	t_stack	stack_b;
	int		counter;
	char	*output;

	if (argc == 1)
		exit(EXIT_FAILURE);
	stack_a = simplified_values(init_stack_a(argv_stack(argc, argv)));
	stack_b = init_stack_b(stack_a);
	counter = 0;
	while (1)
	{
		output = get_next_line(0);
		if (output == 0)
			break ;
		check_and_make_moves(stack_a, stack_b, output);
		counter++;
	}
	check_sort_result(stack_a);
	ft_putstr_fd("Sorted in ", 1);
	ft_putnbr_fd(counter, 1);
	ft_putstr_fd(" moves.\n", 1);
	exit(EXIT_SUCCESS);
	return (0);
}
