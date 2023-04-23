#include "push_swap.h"

t_stack	basic_algorithm(t_stack stack_a)
{
	int	i;

	i = 0;
	while (stack_a.simplified_values[i] == 0)
		i++;
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

int	empty_array_check(t_stack stack)
{
	int	i;

	i = 0;
	while (stack.simplified_values[i] == 0 && i < stack.len)
		i++;
	if (i == stack.len)
		return (-1);
	return (0);
}

void	move_values(t_stack stack_a, t_stack stack_b, t_cost move)
{
	t_movs	times;

	times.a = 0;
	times.b = 0;
	times.ab = 0;
	if ((move.a < 0 && move.b < 0) && (move.a > move.b))
	{
		times.ab = move.a;
		times.b = move.b - move.a;
	}
	else if ((move.a < 0 && move.b < 0) && (move.a < move.b))
	{
		times.ab = move.b;
		times.a = move.a - move.b;
	}
	else if ((move.a > 0 && move.b > 0) && (move.a < move.b))
	{
		times.ab = move.a;
		times.b = move.b - move.a;
	}
	else if ((move.a > 0 && move.b > 0) && (move.a > move.b))
	{
		times.ab = move.b;
		times.a = move.a - move.b;
	}
	else
	{
		times.a = move.a;
		times.b = move.b;
	}
	make_move(stack_a, stack_b, times);
}

void	make_move(t_stack stack_a, t_stack stack_b, t_movs times)
{
	if (times.a > 0)
	{
		while (times.a > 0)
		{
			rotate(stack_a);
			times.a--;
		}
	}
	if (times.a < 0)
	{
		while (times.a < 0)
		{
			rev_rotate(stack_a);
			times.a++;
		}
	}
	if (times.b > 0)
	{
		while (times.b > 0)
		{
			rotate(stack_b);
			times.b--;
		}
	}
	if (times.b < 0)
	{
		while (times.b < 0)
		{
			rev_rotate(stack_b);
			times.b++;
		}
	}
	if (times.ab > 0)
	{
		while (times.ab > 0)
		{
			rotate_ab(stack_a, stack_b);
			times.ab--;
		}
	}
	if (times.ab < 0)
	{
		while (times.ab < 0)
		{
			rev_rotate_ab(stack_a, stack_b);
			times.ab++;
		}
	}
}
void	push_to_stack_b(t_stack stack_a, t_stack stack_b)
{
	int	n;

	n = 0;
	while (n < (stack_a.len - 3))
	{
		push(stack_b, stack_a);
		n++;
	}
}

void	sorting_stacks(t_stack stack_a, t_stack stack_b)
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
			// if (move.sum != 0)
			// {
			// 	printf("\n\nmove[%d] = %d\n", i, move.sum);
			// 	printf("move_a[%d] = %d\n", i, move.a);
			// 	printf("move_b[%d] = %d\n\n", i, move.b);
			// }
			i++;
		}
		move_values(stack_a, stack_b, best_move);
		push(stack_a, stack_b);
		//printfunction(stack_a, stack_b);
	}
	//printf("\n\n\n\n");
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









































void	printfunction(t_stack stack_a, t_stack stack_b)
{
	int i = 0;
	printf("\n");
	while (i < stack_a.len)
	{
		printf("%d\t\t%d\t\t----%d\n", stack_a.simplified_values[i], stack_b.simplified_values[i], i);
		i++;
	}
	printf("_\t\t_\t\t    _\n");
	printf("a\t\tb\t\t    i");
}
