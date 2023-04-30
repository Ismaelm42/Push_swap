/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_make_moves.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imoro-sa <imoro-sa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/26 10:26:09 by imoro-sa          #+#    #+#             */
/*   Updated: 2023/04/26 10:26:10 by imoro-sa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_movs	move_values(t_cost move)
{
	t_movs	times;

	times.a = 0;
	times.b = 0;
	times.ab = 0;
	if (((move.a < 0 && move.b < 0) && (move.a > move.b))
		|| ((move.a > 0 && move.b > 0) && (move.a < move.b)))
	{
		times.ab = move.a;
		times.b = move.b - move.a;
	}
	else if (((move.a < 0 && move.b < 0) && (move.a < move.b))
		|| ((move.a > 0 && move.b > 0) && (move.a > move.b)))
	{
		times.ab = move.b;
		times.a = move.a - move.b;
	}
	else
	{
		times.a = move.a;
		times.b = move.b;
	}
	return (times);
}

void	make_move_stack_a(int times, t_stack stack)
{
	if (times > 0)
	{
		while (times > 0)
		{
			rotate(stack);
			times--;
		}
	}
	if (times < 0)
	{
		while (times < 0)
		{
			rev_rotate(stack);
			times++;
		}
	}
}

void	make_move_stack_b(int times, t_stack stack)
{
	if (times > 0)
	{
		while (times > 0)
		{
			rotate(stack);
			times--;
		}
	}
	if (times < 0)
	{
		while (times < 0)
		{
			rev_rotate(stack);
			times++;
		}
	}
}

void	make_move_stack_ab(int times, t_stack stack_a, t_stack stack_b)
{
	if (times > 0)
	{
		while (times > 0)
		{
			rotate_ab(stack_a, stack_b);
			times--;
		}
	}
	if (times < 0)
	{
		while (times < 0)
		{
			rev_rotate_ab(stack_a, stack_b);
			times++;
		}
	}
}

void	make_moves(t_stack stack_a, t_stack stack_b, t_cost move)
{
	t_movs	times;

	times = move_values(move);
	make_move_stack_a(times.a, stack_a);
	make_move_stack_b(times.b, stack_b);
	make_move_stack_ab(times.ab, stack_a, stack_b);
}
