/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_movs.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imoro-sa <imoro-sa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/26 10:27:08 by imoro-sa          #+#    #+#             */
/*   Updated: 2023/04/28 13:45:03 by imoro-sa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(t_stack stack)
{
	int	i;
	int	nbr;

	i = 0;
	while (i < stack.len && stack.simplified_values[i] == 0)
		i++;
	if (i < stack.len - 1)
	{
		nbr = stack.simplified_values[i];
		stack.simplified_values[i] = stack.simplified_values[i + 1];
		stack.simplified_values[i + 1] = nbr;
	}
	if (stack.print_flag != 1)
		ft_printf("s%c\n", stack.id);
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
		ft_printf("p%c\n", stack_a.id);
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
		ft_printf("r%c\n", stack.id);
}

void	rev_rotate(t_stack stack)
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
		nbr = stack.simplified_values[i];
		stack.simplified_values[i] = stack.simplified_values[stack.len - 1];
		j = (i + 1);
		while (j < stack.len)
		{
			save = stack.simplified_values[j];
			stack.simplified_values[j] = nbr;
			nbr = save;
			j++;
		}
	}
	if (stack.print_flag != 1)
		ft_printf("rr%c\n", stack.id);
}
