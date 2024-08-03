/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbelkace <nbelkace@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/02 22:17:26 by nbelkace          #+#    #+#             */
/*   Updated: 2024/08/03 06:44:56 by nbelkace         ###   ########.fr       */
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

int	find_min_value(t_stack **a)
{
	t_stack	*current;
	long	min_value;
	int		min_index;

	current = *a;
	min_value = LONG_MAX;
	set_index(*a);
	min_index = current->index;
	while (current != NULL)
	{
		if (current->index < min_index)
		{
			min_index = current->index;
			min_value = current->value;
		}
		current = current->next;
	}
	return (min_value);
}

void	min_on_top(t_stack **a)
{
	long	min_value;
	int	len_a;

	len_a = stack_len(*a);
	min_value = find_min_value(a);
	if (min_value > len_a / 2)
	{
		while (min_value < len_a)
		{
			rra(a);
			min_value++;
		}
	}
	else
	{
		while (min_value > 0)
		{
			ra(a);
			min_value--;
		}
	}
}
