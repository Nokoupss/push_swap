/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cost_analysis.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbelkace <nbelkace@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/27 02:20:45 by nbelkace          #+#    #+#             */
/*   Updated: 2024/08/03 06:17:58 by nbelkace         ###   ########.fr       */
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
		ft_printf("Node %d push_cost_a: %d\n", a->value, a->push_cost_a);
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
		ft_printf("Node %d push_cost_target_b: %d\n", b->value, b->push_cost_target_b);
		b = b->next;
	}
}

int	calculate_total_cost(t_stack *a)
{
	int	total_cost;

	if (a->push_cost_a > 0 && a->target_node->push_cost_target_b > 0)
	{
		if (a->push_cost_a > a->target_node->push_cost_target_b)
			total_cost = a->push_cost_a;
		else
			total_cost = a->target_node->push_cost_target_b;
	}
	else if (a->push_cost_a < 0 && a->target_node->push_cost_target_b < 0)
	{
		if (ft_abs(a->push_cost_a) > ft_abs(a->target_node->push_cost_target_b))
			total_cost = ft_abs(a->push_cost_a);
		else
			total_cost = ft_abs(a->target_node->push_cost_target_b);
	}
	else
		total_cost = ft_abs(a->push_cost_a) + ft_abs(a->target_node->push_cost_target_b);
	return total_cost;
}

void	set_cheapest(t_stack *a)
{
	t_stack	*cheapest_node;
	long	cheapest_value;
	int		total_cost;

	if (a == NULL)
		return;
	cheapest_node = NULL;
	cheapest_value = LONG_MAX;
	while (a != NULL)
	{
		if (a->target_node != NULL)
		{
			total_cost = calculate_total_cost(a);
			if (total_cost < cheapest_value)
			{
				cheapest_value = total_cost;
				cheapest_node = a;
			}
		}
		a = a->next;
	}
	if (cheapest_node != NULL)
		cheapest_node->cheapest = true;
}
