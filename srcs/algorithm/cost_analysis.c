/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cost_analysis.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbelkace <nbelkace@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/27 02:20:45 by nbelkace          #+#    #+#             */
/*   Updated: 2024/07/30 07:05:42 by nbelkace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	set_index(t_stack *stack)
{
	int	i;
	int	median;

	i = 0;
	if (stack == NULL)
		return ;
	median = stack_len(stack) / 2;
	while (stack != NULL)
	{
		stack->index = i;
		if (i <= median)
			stack->above_median = true;
		else
			stack->above_median = false;
		stack = stack->next;
		i++;
	}
}

void	cost_analysis_a(t_stack *a)
{
	int	len_a;

	len_a = stack_len(a);
	while (a != NULL)
	{
		if (a->above_median == true)
			a->push_cost_a = a->index;
		if (a->above_median == false)
			a->push_cost_a = (len_a - (a->index)) * -1;
		a = a->next;
	}
}

void	cost_analysis_target_b(t_stack *b)
{
	int	len_b;

	len_b = stack_len(b);
	while (b != NULL)
	{
		if (b->above_median == true)
			b->push_cost_target_b = b->index;
		if (b->above_median == false)
			b->push_cost_target_b = (len_b - (b->index)) * -1;
		b = b->next;
	}
}

void	set_cheapest(t_stack *a, t_stack *b)
{
	t_stack	*cheapest_node;
	long	cheapest_value;

	if (a == NULL)
		return ;
	cheapest_value = LONG_MAX;
	while (a != NULL)
	{
		if ((a->push_cost_a + b->push_cost_target_b) < cheapest_value)
		{
			cheapest_value = (a->push_cost_a + b->push_cost_target_b);
			cheapest_node = a;
		}
		a = a->next;
	}
	cheapest_node->cheapest = true;
}

