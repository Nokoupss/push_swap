/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stacks.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbelkace <nbelkace@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/30 06:15:23 by nbelkace          #+#    #+#             */
/*   Updated: 2024/08/06 07:41:05 by nbelkace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	sort_stacks(t_stack **a, t_stack **b)
{
	int		len_a;

	push_2_to_b(a, b);
	len_a = stack_len(*a);
	while (len_a > 3)
	{
		init_data_a(*a, *b);
		rotate_all(*a, *b);
		pb(a, b);
		len_a--;
		ft_printf("Stack A : \n");
		print_stack(*a);
		ft_printf("Stack B : \n");
		print_stack(*b);
	}
	sort_three(a);
	while (*b != NULL)
	{
		init_data_b(*a, *b);
		rotate_all(*a, *b);
		pa(b, a);
		ft_printf("Stack B : \n");
		print_stack(*b);
		ft_printf("Stack A : \n");
		print_stack(*a);
	}
	if (is_sorted(*a) == false)
		min_on_top(a);
}
