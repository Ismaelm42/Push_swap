/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_movs_ab.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imoro-sa <imoro-sa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/26 10:27:01 by imoro-sa          #+#    #+#             */
/*   Updated: 2023/04/26 10:34:33 by imoro-sa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap_ab(t_stack stack_a, t_stack stack_b)
{
	stack_a.print_flag = 1;
	stack_b.print_flag = 1;
	swap(stack_a);
	swap(stack_b);
	stack_a.print_flag = 0;
	stack_b.print_flag = 0;
	ft_printf("ss\n");
}

void	rotate_ab(t_stack stack_a, t_stack stack_b)
{
	stack_a.print_flag = 1;
	stack_b.print_flag = 1;
	rotate(stack_a);
	rotate(stack_b);
	stack_a.print_flag = 0;
	stack_b.print_flag = 0;
	ft_printf("rr\n");
}

void	rev_rotate_ab(t_stack stack_a, t_stack stack_b)
{
	stack_a.print_flag = 1;
	stack_b.print_flag = 1;
	rev_rotate(stack_a);
	rev_rotate(stack_b);
	stack_a.print_flag = 0;
	stack_b.print_flag = 0;
	ft_printf("rrr\n");
}
