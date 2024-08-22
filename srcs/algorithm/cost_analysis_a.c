/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cost_analysis_a.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbelkace <nbelkace@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/27 02:20:45 by nbelkace          #+#    #+#             */
/*   Updated: 2024/08/22 04:40:09 by nbelkace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

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

long	calculate_total_cost_a(t_stack *stack)
{
	long	total_cost;

	if (stack->push_cost_a > 0 && stack->target_node->push_cost_b > 0)
	{
		if (stack->push_cost_a > stack->target_node->push_cost_b)
			total_cost = stack->push_cost_a;
		else
			total_cost = stack->target_node->push_cost_b;
	}
	else if (stack->push_cost_a < 0 && stack->target_node->push_cost_b < 0)
	{
		if (ft_abs(stack->push_cost_a)
			> ft_abs(stack->target_node->push_cost_b))
			total_cost = ft_abs(stack->push_cost_a);
		else
			total_cost = ft_abs(stack->target_node->push_cost_b);
	}
	else
		total_cost = ft_abs(stack->push_cost_a)
			+ ft_abs(stack->target_node->push_cost_b);
	return (total_cost);
}

t_stack	*set_cheapest_a(t_stack *stack)
{
	t_stack	*cheapest_node;
	long	cheapest_value;
	int		total_cost;

	if (stack == NULL)
		return (NULL);
	cheapest_node = NULL;
	cheapest_value = LONG_MAX;
	while (stack != NULL)
	{
		if (stack->target_node != NULL)
		{
			total_cost = calculate_total_cost_a(stack);
			if (total_cost < cheapest_value)
			{
				cheapest_value = total_cost;
				cheapest_node = stack;
			}
		}
		stack = stack->next;
	}
	return (cheapest_node);
}
