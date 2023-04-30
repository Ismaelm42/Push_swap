/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_target.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imoro-sa <imoro-sa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/26 10:27:13 by imoro-sa          #+#    #+#             */
/*   Updated: 2023/04/26 10:27:14 by imoro-sa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	target_low_limit(int surface, t_stack stack)
{
	int	n;
	int	nbr;
	int	target;

	nbr = stack.simplified_values[surface];
	target = surface;
	n = surface + 1;
	while (n < stack.len)
	{
		if (nbr > stack.simplified_values[n])
		{
			nbr = stack.simplified_values[n];
			target = n;
		}	
		n++;
	}
	return (target);
}

int	target_high_limit(int surface, t_stack stack)
{
	int	n;
	int	nbr;
	int	target;

	nbr = stack.simplified_values[surface];
	target = surface;
	n = surface + 1;
	while (n < stack.len)
	{
		if (nbr < stack.simplified_values[n])
		{
			nbr = stack.simplified_values[n];
			target = n;
		}	
		n++;
	}
	if (target == stack.len - 1)
		return (surface);
	if (target == surface)
		return (surface + 1);
	target = target + 1;
	return (target);
}

int	target_stack_index(int i, t_stack stack_a, t_stack stack_b)
{
	int	n;
	int	target;
	int	surface;

	n = 0;
	while (stack_a.simplified_values[n] == 0)
		n++;
	surface = n;
	while (n < stack_a.len)
	{
		target = n + 1;
		if (n == stack_a.len - 1)
			target = surface;
		if (stack_b.simplified_values[i] > stack_a.simplified_values[n]
			&& stack_b.simplified_values[i] < stack_a.simplified_values[target])
			return (target);
		n++;
	}
	if (stack_b.simplified_values[i] < stack_a.simplified_values[surface])
		return (target_low_limit(surface, stack_a));
	return (target_high_limit(surface, stack_a));
}
