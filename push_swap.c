/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imoro-sa <imoro-sa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/26 10:27:24 by imoro-sa          #+#    #+#             */
/*   Updated: 2023/04/28 13:46:02 by imoro-sa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	basic_algorithm(t_stack stack_a)
{
	int	i;

	i = 0;
	while (stack_a.simplified_values[i] == 0)
		i++;
	if (stack_a.len == 2
		&& stack_a.simplified_values[i] > stack_a.simplified_values[i + 1])
	{
		swap(stack_a);
		exit(EXIT_SUCCESS);
	}
	if (stack_a.simplified_values[i + 1] < stack_a.simplified_values [i + 2]
		&& stack_a.simplified_values[i + 2] < stack_a.simplified_values[i])
		return (stack_a);
	if (stack_a.simplified_values[i] > stack_a.simplified_values[i + 1])
		swap(stack_a);
	if (stack_a.simplified_values[i] > stack_a.simplified_values[i + 2])
		rev_rotate(stack_a);
	if (stack_a.simplified_values[i + 1] > stack_a.simplified_values[i + 2])
	{
		rev_rotate(stack_a);
		swap(stack_a);
	}
	return (stack_a);
}

void	push_to_stack_b(t_stack stack_a, t_stack stack_b)
{
	int	n;
	int	middle;

	n = 0;
	middle = stack_a.len / 2;
	while (n < (stack_a.len - 3))
	{
		while (n < middle && (stack_a.len - 3) > middle)
		{
			if (stack_a.simplified_values[n] <= middle)
			{
				push(stack_b, stack_a);
				n++;
			}
			else
				rotate(stack_a);
		}
		push(stack_b, stack_a);
		n++;
	}
}

void	sorting_stack(t_stack stack_a, t_stack stack_b)
{
	t_cost	best_move;
	t_cost	move;
	int		i;

	while (empty_array_check(stack_b) != -1)
	{
		i = 0;
		best_move.sum = 1000;
		while (i < stack_b.len)
		{
			move = move_cost_counter(i, stack_a, stack_b);
			if (move.sum > 0 && move.sum < best_move.sum)
				best_move = move;
			i++;
		}
		make_moves(stack_a, stack_b, best_move);
		push(stack_a, stack_b);
	}
}

void	rearrange_stack(t_stack stack)
{
	int	i;

	i = 0;
	while (stack.simplified_values[i] != 1)
		i++;
	if (i < (stack.len / 2))
	{
		while (i > 0)
		{
			rotate(stack);
			i--;
		}
	}
	else
	{
		while (i < stack.len)
		{
			rev_rotate(stack);
			i++;
		}
	}
}

void	push_swap(int argc, char **argv)
{
	t_stack	stack_a;
	t_stack	stack_b;

	if (argc == 1)
		exit(EXIT_SUCCESS);
	stack_a = init_stack_a(argv_stack(argc, argv));
	check_already_sorted(stack_a);
	stack_a = simplified_values(stack_a);
	stack_b = init_stack_b(stack_a);
	push_to_stack_b(stack_a, stack_b);
	stack_a = basic_algorithm(stack_a);
	sorting_stack(stack_a, stack_b);
	free(stack_b.simplified_values);
	rearrange_stack(stack_a);
	free(stack_a.simplified_values);
}
