#include "push_swap.h"

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

void	int_error(void)
{
	ft_putstr_fd("Error\n", 2);
	exit(EXIT_FAILURE);
}

int	abs_value(int a)
{
	if (a < 0)
		a = a * -1;
	return (a);
}

int	empty_array_check(t_stack stack)
{
	int	i;

	i = 0;
	while (stack.simplified_values[i] == 0 && i < stack.len)
		i++;
	if (i == stack.len && stack.simplified_values[i - 1] == 0)
		return (-1);
	return (0);
}
