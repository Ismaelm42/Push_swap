/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imoro-sa <imoro-sa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/17 12:22:43 by imoro-sa          #+#    #+#             */
/*   Updated: 2023/04/17 14:10:57 by imoro-sa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "./libft/libft.h"

typedef struct s_stack
{
	int		*simplified_values;
	int		*values;
	int		print_flag;
	int		len;
	char	id;
}	t_stack;

char		**argv_stack(int argc, char **argv);
t_stack		init_stack_a(char **argv_stack);
t_stack		init_stack_b(t_stack stack_a);

void		int_error(void);
void		check_int_numbers(char **argv_stack);
long int	push_swap_atoi(const char *str);
void		check_dup_stack_a(t_stack stack_a);
int			lowest_nbr(t_stack stack_a);
t_stack		simplified_values(t_stack stack_a);

void		swap(t_stack stack);
void		swap_ab(t_stack stack_a, t_stack stack_b);
void		push(t_stack stack_a, t_stack stack_b);
void		rotate(t_stack stack);
void		rev_rotate(t_stack stack);
void		rev_rotate_ab(t_stack stack_a, t_stack stack_b);
void		printfunction(t_stack stack_a, t_stack stack_b);

#endif