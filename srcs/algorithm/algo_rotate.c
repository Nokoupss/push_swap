/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_rotate.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbelkace <nbelkace@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/30 04:58:52 by nbelkace          #+#    #+#             */
/*   Updated: 2024/08/07 08:24:09 by nbelkace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	rotate_both_stacks(t_stack **a, t_stack **b)
{
	while ((*a)->push_cost_a > 0 && (*a)->target_node->push_cost_b > 0)
	{
		(*a)->push_cost_a--;
		(*a)->target_node->push_cost_b--;
		rr(a, b);
	}
}

void	reverse_rotate_both_stacks(t_stack **a, t_stack **b)
{
	while ((*a)->push_cost_a < 0 && (*a)->target_node->push_cost_b < 0)
	{
		(*a)->push_cost_a++;
		(*a)->target_node->push_cost_b++;
		rrr(a, b);
	}
}

void	rotate_stack_a(t_stack **a, int push_cost_a)
{
	while (push_cost_a != 0)
	{
		if (push_cost_a > 0)
		{
			push_cost_a--;
			ra(a);
		}
		if (push_cost_a < 0)
		{
			push_cost_a++;
			rra(a);
		}
	}
}

void	rotate_stack_b(t_stack **b, int push_cost_b)
{
	while (push_cost_b != 0)
	{
		if (push_cost_b > 0)
		{
			push_cost_b--;
			rb(b);
		}
		if (push_cost_b < 0)
		{
			push_cost_b++;
			rrb(b);
		}
	}
}

void	rotate_all(t_stack **a, t_stack **b, t_stack *cheapest_node)
{
	if (cheapest_node != NULL && cheapest_node->target_node != NULL)
	{
		rotate_both_stacks(a, b);
		reverse_rotate_both_stacks(a, b);
		rotate_stack_a(a, cheapest_node->push_cost_a);
		rotate_stack_b(b, cheapest_node->target_node->push_cost_b);
	}
}
