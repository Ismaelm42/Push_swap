/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_movs_ab.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imoro-sa <imoro-sa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/28 13:28:08 by imoro-sa          #+#    #+#             */
/*   Updated: 2023/04/28 13:29:38 by imoro-sa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	quiet_swap_ab(t_stack stack_a, t_stack stack_b)
{
	quiet_swap(stack_a);
	quiet_swap(stack_b);
}

void	quiet_rotate_ab(t_stack stack_a, t_stack stack_b)
{
	quiet_rotate(stack_a);
	quiet_rotate(stack_b);
}

void	quiet_rev_rotate_ab(t_stack stack_a, t_stack stack_b)
{
	quiet_rev_rotate(stack_a);
	quiet_rev_rotate(stack_b);
}
