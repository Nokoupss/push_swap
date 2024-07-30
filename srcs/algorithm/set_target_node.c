/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_target_node.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbelkace <nbelkace@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/26 00:37:30 by nbelkace          #+#    #+#             */
/*   Updated: 2024/07/30 07:02:56 by nbelkace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	push_2_to_b(t_stack **a, t_stack **b)
{
	if ((a) == NULL || (b) == NULL)
		return ;
	if (stack_len(*a) > 4)
	{
		pb(a, b);
		pb(a, b);
	}
	else if (stack_len(*a) == 4)
		pb(a, b);
}

t_stack	*find_closest_smaller(t_stack *b, int value)
{
	t_stack	*closest_smaller;
	t_stack	*current;
	int		min_diff;
	int		diff;

	closest_smaller = NULL;
	current = b;
	min_diff = INT_MAX;
	while (current != NULL)
	{
		diff = value - current->value;
		if (diff > 0 && diff < min_diff)
		{
			min_diff = diff;
			closest_smaller = current;
		}
		current = current->next;
	}
	if (closest_smaller == NULL)
		closest_smaller = find_max_node(b);
	return (closest_smaller);
}

void	set_target_node_a(t_stack *a, t_stack *b)
{
	t_stack	*current_a;

	current_a = a;
	while (current_a != NULL)
	{
		current_a->target_node = find_closest_smaller(b, current_a->value);
		current_a = current_a->next;
	}
}

t_stack	*find_closest_bigger(t_stack *a, int value)
{
	t_stack	*closest_bigger;
	t_stack	*current;
	long		min_diff;
	int		diff;

	closest_bigger = NULL;
	current = a;
	min_diff = LONG_MAX;
	while (current != NULL)
	{
		diff = current->value - value;
		if (diff > 0 && diff < min_diff)
		{
			min_diff = diff;
			closest_bigger = current;
		}
		current = current->next;
	}
	if (closest_bigger == NULL)
		closest_bigger = find_min_node(a);
	return (closest_bigger);
}

void	set_target_node_b(t_stack *a, t_stack *b)
{
	t_stack	*current_b;

	current_b = b;
	while (current_b != NULL)
	{
		current_b->target_node = find_closest_bigger(a, current_b->value);
		current_b = current_b->next;
	}
}
