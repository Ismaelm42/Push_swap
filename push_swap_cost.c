#include "push_swap.h"

int	move_rotate(int i, t_stack stack)
{
	int	surface;
	int	result;

	surface = 0;
	result = 0;
	while (stack.simplified_values[surface] == 0)
		surface++;
	while (i > surface)
	{
		result++;
		i--;
	}
	return (result);
}

int	move_rev_rotate(int i, t_stack stack)
{
	int	surface;
	int	result;

	surface = 0;
	result = 0;
	while (stack.simplified_values[surface] == 0)
		surface++;
	if (surface == i)
		return (0);
	while (i <= stack.len - 1)
	{
		result++;
		i++;
	}
	return (result * -1);
}

int	select_move(int i, t_stack stack)
{
	int	surface;
	int	result;
	int	length;
	int	j;

	surface = 0;
	while (stack.simplified_values[surface] == 0)
		surface++;
	length = stack.len - surface;
	j = i - surface + 1;
	if (j <= (length / 2) + 1)
		result = move_rotate(i, stack);
	if (j > (length / 2) + 1)
		result = move_rev_rotate(i, stack);
	return (result);
}

t_cost	move_cost_counter(int i, t_stack stack_a, t_stack stack_b)
{
	t_cost	cost;

	if (stack_b.simplified_values[i] == 0)
		return (cost.sum = 0, cost);
	cost.index = i;
	cost.a = select_move(target_stack_index(i, stack_a, stack_b), stack_a);
	cost.b = select_move(i, stack_b);
	if ((cost.a < 0 && cost.b < 0) && (cost.a < cost.b))
		cost.sum = abs_value(cost.b) + abs_value(cost.a - cost.b);
	else if ((cost.a < 0 && cost.b < 0) && (cost.a >= cost.b))
		cost.sum = abs_value(cost.a) + abs_value(cost.b - cost.a);
	else if ((cost.a > 0 && cost.b > 0) && (cost.a < cost.b))
		cost.sum = cost.a + (cost.b - cost.a);
	else if ((cost.a > 0 && cost.b > 0) && (cost.a >= cost.b))
		cost.sum = cost.b + (cost.a - cost.b);
	else
		cost.sum = abs_value(cost.a) + abs_value(cost.b);
	cost.sum = cost.sum + 1;
	return (cost);
}
