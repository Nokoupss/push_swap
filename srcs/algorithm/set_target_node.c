/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_target_node.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbelkace <nbelkace@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/26 00:37:30 by nbelkace          #+#    #+#             */
/*   Updated: 2024/07/26 05:33:24 by nbelkace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	push_a_to_b(t_stack **a, t_stack **b)
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
	t_stack	*closest;
	t_stack	*current;
	int		min_diff;
	int		diff;

	closest = NULL;
	current = b;
	min_diff = INT_MAX;
	while (current != NULL)
	{
		diff = value - current->value;
		if (diff > 0 && diff < min_diff)
		{
			min_diff = diff;
			closest = current;
		}
		current = current->next;
	}
	if (closest == NULL)
		closest = find_max_node(b);
	return (closest);
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
