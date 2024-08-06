/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_three.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbelkace <nbelkace@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/25 04:50:59 by nbelkace          #+#    #+#             */
/*   Updated: 2024/08/06 07:38:04 by nbelkace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	sort_three(t_stack **a)
{
	t_stack	*current;
	int		max;

	if (*a == NULL || (*a)->next == NULL || (*a)->next->next == NULL)
		return ;
	current = *a;
	max = current->value;
	while (current)
	{
		if (current->value > max)
			max = current->value;
		current = current->next;
	}
	if ((*a)->value == max)
		ra(a);
	else if ((*a)->next->value == max)
		rra(a);
	if ((*a)->value > (*a)->next->value)
		sa(a);
}
