#include "push_swap.h"

void	basic_algorithm(t_stack stack_a)
{
	int	i;

	i = 0;
	while (stack_a.simplified_values[i] == 0)
		i++;
	if (stack_a.simplified_values[i] > stack_a.simplified_values[i + 1])
		swap(stack_a);
	if (stack_a.simplified_values[i]  > stack_a.simplified_values[i + 2])
		rev_rotate(stack_a);
	if (stack_a.simplified_values[i + 1] > stack_a.simplified_values[i + 2])
	{
		rev_rotate(stack_a);
		swap(stack_a);
	}
}

int	move_counter_rotate(int i, t_stack stack)
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

int	move_counter_rev_rotate(int i, t_stack stack)
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
	return (result);
}

int	move_counter_supple(int i, t_stack stack)
{
	int	result;

	if (stack.len / 2 <= i)
		result = move_counter_rotate(i, stack);
	if (stack.len / 2 > i)
		result = move_counter_rev_rotate(i, stack);
	return (result);
}

int	target_stack_index(int i, t_stack stack_a, t_stack stack_b)
{
	int	n;

	n = 0;
	while (n < stack_a.len
		&& stack_b.simplified_values[i] > stack_a.simplified_values[n])
		n++;
	if (n == stack_a.len)
		n--;
	return (n);
}

int	move_variation(int i, t_stack stack_a, t_stack stack_b)
{
	int	j;
	int	result_rotate;
	int	result_rev_rotate;
	int	result_supple;

	j = target_stack_index(i, stack_a, stack_b);
	result_rotate = (move_counter_rotate(i, stack_b) + move_counter_rotate(j, stack_a));
	result_rev_rotate = (move_counter_rev_rotate(i, stack_b) + move_counter_rev_rotate(j, stack_a));
	result_supple = (move_counter_supple(i, stack_b) + move_counter_supple(j, stack_a));
	printf("result_rotate = %d\n", result_rotate);
	printf("result_rev_rotate = %d\n", result_rev_rotate);
	printf("result_supple = %d\n", result_supple);
	if (stack_b.simplified_values[i] == 0)
		return (0);
	if (result_rotate > result_rev_rotate && result_rotate > result_supple)
		return (result_rotate + 1);
	if (result_rev_rotate > result_rotate && result_rev_rotate > result_supple)
		return (result_rev_rotate + 1);
	return (result_supple + 1);
}

int	array_check(t_stack stack)
{
	int	i;

	i = 0;
	while (stack.simplified_values[i] == 0)
		i++;
	if (i == stack.len)
		return (-1);
	return (0);
}

t_stack	array_filler(t_stack stack_a, t_stack stack_b)
{
	int	i;

	while (array_check(stack_b) != -1)
	{
		i = 0;
		stack_b.move_cost = malloc(sizeof(int) * stack_b.len);
		while (i < stack_b.len)
		{
			stack_b.move_cost[i] = move_variation(i, stack_a, stack_b);
			i++;
		}
		push(stack_a, stack_b);
	}
	return (stack_b);
}


// int	move_selector()
// 	// len / 2 para saber en que mitad está
// 	// calcular con i cuando para realizar el rotate (negativo o positivo)
// 	// sumar 1 para el push
// 	// hacer lo mismo para recibir el push con el stack a
// 	// si los signos coinciden, dividir por 2 el resultado, ya que se dividiría eso por dos al utilizar una doble función
// 	// establecer el número


// void	move_maker(t_stack stack_a, t_stack stack_b)
// {

// }

// void	complex_algorithm(t_stack stack_a, t_stack stack_b)
// {

// }
