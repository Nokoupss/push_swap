/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_rotate_b_to_a.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbelkace <nbelkace@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/08 07:28:01 by nbelkace          #+#    #+#             */
/*   Updated: 2024/08/19 05:44:26 by nbelkace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	rotate_stack_b_2(t_stack **b, int push_cost_b)
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

void	rotate_stack_a_2(t_stack **a, int push_cost_a)
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

void rotate_all_2(t_stack **b, t_stack **a, t_stack *cheapest_node)
{
    int push_cost_b;
    int push_cost_a;

	push_cost_b = cheapest_node->push_cost_b;
	push_cost_a = cheapest_node->target_node->push_cost_a;
    while (push_cost_b > 0 && push_cost_a > 0)
    {
        push_cost_b--;
        push_cost_a--;
        rr(a, b);
    }
	while (push_cost_b < 0 && push_cost_a < 0)
    {
        push_cost_b++;
        push_cost_a++;
        rrr(a, b);
    }
	rotate_stack_a_2(a, push_cost_a);
	rotate_stack_b_2(b, push_cost_b);
}
