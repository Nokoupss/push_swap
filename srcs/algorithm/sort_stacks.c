/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stacks.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbelkace <nbelkace@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/30 06:15:23 by nbelkace          #+#    #+#             */
/*   Updated: 2024/08/03 07:36:45 by nbelkace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	sort_stacks(t_stack **a, t_stack **b)
{
	int		len_a;

	len_a = stack_len(*a);
	while (len_a > 3)
	{
		init_data_a(*a, *b);
		rotate_all(*a, *b);
		pb(a, b);
		len_a--;
	}
	sort_three(a);
	while (*b != NULL)
	{
		init_data_b(*a, *b);
		rotate_all(*b, *a);
		pa(b, a);
	}
	if (is_sorted(*a) == false)
		min_on_top(a);
}
