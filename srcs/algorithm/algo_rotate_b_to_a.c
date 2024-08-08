/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_rotate_b_to_a.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbelkace <nbelkace@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/08 07:28:01 by nbelkace          #+#    #+#             */
/*   Updated: 2024/08/08 08:12:02 by nbelkace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	rotate_both_stacks_test(t_stack **b, t_stack **a)
{
	while ((*b)->push_cost_b > 0 && (*b)->target_node->push_cost_a > 0)
	{
		(*b)->push_cost_b--;
		(*b)->target_node->push_cost_a--;
		rr(a, b);
	}
}

void	reverse_rotate_both_stacks_test(t_stack **b, t_stack **a)
{
	while ((*b)->push_cost_b < 0 && (*b)->target_node->push_cost_a < 0)
	{
		(*b)->push_cost_b++;
		(*b)->target_node->push_cost_a++;
		rrr(a, b);
	}
}

void	rotate_stack_b_test(t_stack **b, int push_cost_b)
{
	while (push_cost_b != 0)
	{
		if (push_cost_b > 0)
		{
			push_cost_b--;
			rb(b);
		}
		else if (push_cost_b < 0)
		{
			push_cost_b++;
			rrb(b);
		}
	}
}

void	rotate_stack_a_test(t_stack **a, int push_cost_a)
{
	while (push_cost_a != 0)
	{
		if (push_cost_a > 0)
		{
			push_cost_a--;
			ra(a);
		}
		else if (push_cost_a < 0)
		{
			push_cost_a++;
			rra(a);
		}
	}
}

void	rotate_all_test(t_stack **b, t_stack **a, t_stack *cheapest_node)
{
	if (cheapest_node != NULL && cheapest_node->target_node != NULL)
	{
		rotate_both_stacks_test(b, a);
		reverse_rotate_both_stacks_test(b, a);
		rotate_stack_a_test(a, cheapest_node->target_node->push_cost_a);
		rotate_stack_b_test(b, cheapest_node->push_cost_b);
	}
}
