/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_three.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbelkace <nbelkace@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/25 04:50:59 by nbelkace          #+#    #+#             */
/*   Updated: 2024/07/25 05:11:04 by nbelkace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	sort_three(t_stack **a)
{
	t_stack	*max_node;
	t_stack	*current;

	max_node = find_max_node(*a);
	current = *a;
	if (max_node == current)
		ra(a);
	else if (current->next == max_node)
		rra(a);
	if ((*a)->value > (*a)->next->value)
		sa(a);
}
