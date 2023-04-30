/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_check.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imoro-sa <imoro-sa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/26 10:25:36 by imoro-sa          #+#    #+#             */
/*   Updated: 2023/04/28 13:45:24 by imoro-sa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	check_int_numbers(char **argv_stack)
{
	int	n;
	int	i;

	n = 0;
	if (argv_stack[n] == NULL)
		int_error();
	while (argv_stack[n] != NULL)
	{
		i = 0;
		while (argv_stack[n][i] != 0)
		{
			if ((i == 0)
				&& (argv_stack[n][i] == '-' || argv_stack[n][i] == '+'))
			{
				if (argv_stack[n][i + 1] < '0' || argv_stack[n][i + 1] > '9')
					int_error();
			}
			else if (argv_stack[n][i] < '0' || argv_stack[n][i] > '9')
				int_error();
			i++;
		}
		n++;
	}
}

void	check_dup_stack_a(t_stack stack_a)
{
	int	n;
	int	i;

	n = 0;
	while (n < stack_a.len - 1)
	{
		i = n + 1;
		while (i < stack_a.len)
		{
			if (stack_a.values[n] == stack_a.values[i])
				int_error();
			i++;
		}
		n++;
	}
}

void	check_already_sorted(t_stack stack_a)
{
	int	i;

	i = 0;
	while (i < stack_a.len - 1)
	{
		if (stack_a.values[i] < stack_a.values[i + 1])
			i++;
		else
			break ;
	}
	if (i == stack_a.len - 1)
		exit(EXIT_SUCCESS);
}
