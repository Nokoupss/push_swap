/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbelkace <nbelkace@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/02 22:17:26 by nbelkace          #+#    #+#             */
/*   Updated: 2024/08/08 09:14:07 by nbelkace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

t_stack	*find_max_node(t_stack *stack)
{
	t_stack	*max_node;
	t_stack	*current;

	max_node = stack;
	current = stack;
	if (stack == NULL)
		return (NULL);
	while (current != NULL)
	{
		if (current->value > max_node->value)
			max_node = current;
		current = current->next;
	}
	return (max_node);
}

t_stack	*find_min_node(t_stack *stack)
{
	t_stack	*min_node;
	t_stack	*current;

	min_node = stack;
	current = stack;
	if (stack == NULL)
		return (NULL);
	while (current != NULL)
	{
		if (current->value < min_node->value)
			min_node = current;
		current = current->next;
	}
	return (min_node);
}

int	ft_abs(int nb)
{
	if (nb < 0)
		return(nb * -1);
	return (nb);
}

void	min_on_top(t_stack **a)
{
	int	len_a;
	t_stack	*min_node;

	len_a = stack_len(*a);
	min_node = find_min_node(*a);
	while ((*a)->value != min_node->value)
	{
		if (min_node->above_median == true)
			ra(a);
		else
			rra(a);
	}
}
