/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cost_analysis_b.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbelkace <nbelkace@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/22 04:18:55 by nbelkace          #+#    #+#             */
/*   Updated: 2024/08/22 04:40:37 by nbelkace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	cost_analysis_b(t_stack *b)
{
	int	len_b;

	len_b = stack_len(b);
	while (b != NULL)
	{
		if (b->above_median == true)
			b->push_cost_b = b->index;
		if (b->above_median == false)
			b->push_cost_b = (len_b - (b->index)) * -1;
		b = b->next;
	}
}

long	calculate_total_cost_b(t_stack *b)
{
	long	total_cost;

	if (b->push_cost_b > 0 && b->target_node->push_cost_a > 0)
	{
		if (b->push_cost_b > b->target_node->push_cost_a)
			total_cost = b->push_cost_b;
		else
			total_cost = b->target_node->push_cost_a;
	}
	else if (b->push_cost_b < 0 && b->target_node->push_cost_a < 0)
	{
		if (ft_abs(b->push_cost_b) > ft_abs(b->target_node->push_cost_a))
			total_cost = ft_abs(b->push_cost_b);
		else
			total_cost = ft_abs(b->target_node->push_cost_a);
	}
	else
		total_cost = ft_abs(b->push_cost_b)
			+ ft_abs(b->target_node->push_cost_a);
	return (total_cost);
}

t_stack	*set_cheapest_b(t_stack *b)
{
	t_stack	*cheapest_node;
	long	cheapest_value;
	int		total_cost;

	cheapest_node = NULL;
	cheapest_value = LONG_MAX;
	if (b == NULL)
		return (NULL);
	while (b != NULL)
	{
		if (b->target_node != NULL)
		{
			total_cost = calculate_total_cost_b(b);
			if (total_cost < cheapest_value)
			{
				cheapest_value = total_cost;
				cheapest_node = b;
			}
		}
		b = b->next;
	}
	return (cheapest_node);
}
