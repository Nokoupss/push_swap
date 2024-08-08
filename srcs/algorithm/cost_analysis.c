/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cost_analysis.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbelkace <nbelkace@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/27 02:20:45 by nbelkace          #+#    #+#             */
/*   Updated: 2024/08/08 11:40:46 by nbelkace         ###   ########.fr       */
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

long	calculate_total_cost(t_stack *stack)
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
		if (ft_abs(stack->push_cost_a) > ft_abs(stack->target_node->push_cost_b))
			total_cost = ft_abs(stack->push_cost_a);
		else
			total_cost = ft_abs(stack->target_node->push_cost_b);
	}
	else
		total_cost = ft_abs(stack->push_cost_a) + ft_abs(stack->target_node->push_cost_b);
	return (total_cost);
}

t_stack	*set_cheapest(t_stack *stack)
{
	t_stack	*cheapest_node;
	long	cheapest_value;
	int		total_cost;

	if (stack == NULL)
		return NULL;
	cheapest_node = NULL;
	cheapest_value = LONG_MAX;
	while (stack != NULL)
	{
		if (stack->target_node != NULL)
		{
			total_cost = calculate_total_cost(stack);
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

long	calculate_total_cost_b_to_a(t_stack *b)
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
		total_cost = ft_abs(b->push_cost_b) + ft_abs(b->target_node->push_cost_a);
	return (total_cost);
}

t_stack	*set_cheapest_b_to_a(t_stack *b)
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
			total_cost = calculate_total_cost_b_to_a(b);
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
