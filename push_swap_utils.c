/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imoro-sa <imoro-sa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/17 12:22:24 by imoro-sa          #+#    #+#             */
/*   Updated: 2023/04/17 14:16:33 by imoro-sa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	int_error(void)
{
	ft_putstr_fd("Error\n", 2);
	exit(EXIT_FAILURE);
}

void	check_int_numbers(char **argv_stack)
{
	int	n;
	int	i;

	n = 0;
	while (argv_stack[n] != NULL)
	{
		i = 0;
		while (argv_stack[n][i] != 0)
		{
			if (argv_stack[n][i] == '-' || argv_stack[n][i] == '+')
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

long int	push_swap_atoi(const char *str)
{
	long int	i;
	long int	j;
	long int	k;

	i = 0;
	while (str[i] == 32 || str[i] == 12 || str[i] == 10
		|| str[i] == 13 || str[i] == 11 || str[i] == 9)
		i++;
	k = 1;
	if (str[i] == 45 || str[i] == 43)
	{
		if (str[i] == 45)
			k = -1;
		i++;
	}
	j = 0;
	while (str[i] > 47 && str[i] < 58)
	{
		j = j * 10 + str[i] - '0';
		i++;
	}
	if ((k * j) < -2147483648 || (k *j) > 2147483647)
		int_error();
	return ((k * j));
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

int	lowest_nbr(t_stack stack_a)
{
	int	n;
	int	i;
	int	low_nbr;

	n = 1;
	i = 0;
	low_nbr = stack_a.values[0];
	while (n < stack_a.len)
	{
		if (stack_a.values[n] < low_nbr)
		{
			low_nbr = stack_a.values[n];
			i = n;
		}
		n++;
	}
	return (i);
}

t_stack	simplified_values(t_stack stack_a)
{
	int	i;
	int	n;
	int	counter;

	stack_a.simplified_values = malloc(sizeof(int) * stack_a.len);
	stack_a.simplified_values[lowest_nbr(stack_a)] = 1;
	n = stack_a.values[lowest_nbr(stack_a)] + 1;
	counter = 1;
	while (counter < stack_a.len)
	{
		i = 0;
		while (i < stack_a.len)
		{
			if (stack_a.values[i] == n)
			{
				stack_a.simplified_values[i] = counter + 1;
				counter++;
			}
			i++;
		}
		n++;
	}
	return (stack_a);
}


























































void	printfunction(t_stack stack_a, t_stack stack_b)
{
	int i = 0;
	printf("\n");
	while (i < stack_a.len)
	{
		printf("%d  %d\n", stack_a.simplified_values[i], stack_b.simplified_values[i]);
		i++;
	}
	printf("_  _\n");
	printf("a  b\n");
}
