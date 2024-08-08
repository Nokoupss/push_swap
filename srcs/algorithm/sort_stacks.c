/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stacks.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbelkace <nbelkace@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/30 06:15:23 by nbelkace          #+#    #+#             */
/*   Updated: 2024/08/08 11:41:12 by nbelkace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	sort_stacks(t_stack **a, t_stack **b)
{
	int		len_a;
	t_stack	*cheapest_node;

	push_2_to_b(a, b);
	len_a = stack_len(*a);
	while (len_a > 3)
	{
		cheapest_node = init_data_a(*a, *b);
		rotate_all(a, b, cheapest_node);
		pb(a, b);
		len_a--;
	}
	sort_three(a);
	while (*b != NULL)
	{
		cheapest_node = init_data_b(*a, *b);
		rotate_all_test(b, a, cheapest_node);
		pa(b, a);
	}
	if (is_sorted(*a) == false)
		min_on_top(a);
}
