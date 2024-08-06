/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_rotate.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbelkace <nbelkace@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/30 04:58:52 by nbelkace          #+#    #+#             */
/*   Updated: 2024/08/06 08:34:15 by nbelkace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	rotate_both_stacks(t_stack *a, t_stack *b)
{
	while (a->push_cost_a > 0 && a->target_node->push_cost_target_b > 0)
	{
		a->push_cost_a--;
		a->target_node->push_cost_target_b--;
		rr(&a, &b);
	}
}

void	reverse_rotate_both_stacks(t_stack *a, t_stack *b)
{
	while (a->push_cost_a < 0 && a->target_node->push_cost_target_b < 0)
	{
		a->push_cost_a++;
		a->target_node->push_cost_target_b++;
		rrr(&a, &b);
	}
}

void	rotate_stack_a(t_stack *a, int push_cost_a)
{
	while (push_cost_a != 0)
	{
		if (push_cost_a > 0)
			{
				push_cost_a--;
				ra(&a);
			}
		if (push_cost_a < 0)
			{
				push_cost_a++;
				rra(&a);
			}
	}
}

void	rotate_stack_b(t_stack *b, int push_cost_target_b)
{
	while (push_cost_target_b != 0)
	{
		if (push_cost_target_b > 0)
			{
				push_cost_target_b--;
				rb(&b);
			}
		if (push_cost_target_b < 0)
			{
				push_cost_target_b++;
				rrb(&b);
			}
	}
}

void	rotate_all(t_stack *a, t_stack *b)
{
	if (a != NULL && a->target_node != NULL)
	{
		set_target_node_a(a, b);
		set_target_node_b(b, a);
		cost_analysis_a(a);
		cost_analysis_target_b(b);
		rotate_both_stacks(a, b);
		reverse_rotate_both_stacks(a, b);
		rotate_stack_a(a, a->push_cost_a);
		rotate_stack_b(b, a->target_node->push_cost_target_b);
	}
}
