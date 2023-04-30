/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_movs.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imoro-sa <imoro-sa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/28 13:15:52 by imoro-sa          #+#    #+#             */
/*   Updated: 2023/04/28 13:19:46 by imoro-sa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	quiet_swap(t_stack stack)
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
}

void	quiet_push(t_stack stack_a, t_stack stack_b)
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
	}
}

void	quiet_rotate(t_stack stack)
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
}

void	quiet_rev_rotate(t_stack stack)
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
}
