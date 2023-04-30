/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imoro-sa <imoro-sa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/26 10:27:49 by imoro-sa          #+#    #+#             */
/*   Updated: 2023/04/28 16:22:20 by imoro-sa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	result_output(t_stack stack_a, int flag, int index)
{
	if (index == stack_a.len - 1)
	{
		ft_printf("OK\n");
		if (flag == 1)
		{
			ft_printf("Already sorted. No move required.");
			exit(EXIT_SUCCESS);
		}
	}
	else
	{
		if (flag == 0)
		{
			ft_printf("KO\n");
			exit(EXIT_FAILURE);
		}
	}
}

void	check_sort_result(t_stack stack_a, int flag)
{
	int	i;

	i = 0;
	while (i < stack_a.len - 1)
	{
		if (stack_a.simplified_values[i] < stack_a.simplified_values[i + 1]
			&& stack_a.simplified_values[i] != 0)
			i++;
		else
			break ;
	}
	result_output(stack_a, flag, i);
}

void	exec_moves(t_stack stack_a, t_stack stack_b, char *output)
{
	if (ft_strncmp("sa\n", output, 3) == 0)
		quiet_swap(stack_a);
	else if (ft_strncmp("sb\n", output, 3) == 0)
		quiet_swap(stack_b);
	else if (ft_strncmp("ss\n", output, 3) == 0)
		quiet_swap_ab(stack_a, stack_b);
	else if (ft_strncmp("pa\n", output, 3) == 0)
		quiet_push(stack_a, stack_b);
	else if (ft_strncmp("pb\n", output, 3) == 0)
		quiet_push(stack_b, stack_a);
	else if (ft_strncmp("ra\n", output, 3) == 0)
		quiet_rotate(stack_a);
	else if (ft_strncmp("rb\n", output, 3) == 0)
		quiet_rotate(stack_b);
	else if (ft_strncmp("rr\n", output, 3) == 0)
		quiet_rotate_ab(stack_a, stack_b);
	else if (ft_strncmp("rra\n", output, 4) == 0)
		quiet_rev_rotate(stack_a);
	else if (ft_strncmp("rrb\n", output, 4) == 0)
		quiet_rev_rotate(stack_b);
	else if (ft_strncmp("rrr\n", output, 4) == 0)
		quiet_rev_rotate_ab(stack_a, stack_b);
	else
		int_error();
}

int	main(int argc, char **argv)
{
	t_stack	stack_a;
	t_stack	stack_b;
	int		flag;
	int		counter;
	char	*output;

	flag = 1;
	if (argc == 1)
		exit(EXIT_FAILURE);
	stack_a = simplified_values(init_stack_a(argv_stack(argc, argv)));
	check_sort_result(stack_a, flag);
	flag = 0;
	stack_b = init_stack_b(stack_a);
	counter = 0;
	while (1)
	{
		output = get_next_line(0);
		if (output == 0)
			break ;
		exec_moves(stack_a, stack_b, output);
		counter++;
	}
	check_sort_result(stack_a, flag);
	ft_printf("Sorted in %d moves.", counter);
	exit(EXIT_SUCCESS);
}
