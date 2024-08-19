/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbelkace <nbelkace@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/25 03:44:10 by nbelkace          #+#    #+#             */
/*   Updated: 2024/08/18 19:58:13 by nbelkace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

int	stack_len(t_stack *stack)
{
	int	len;

	len = 0;
	while (stack != NULL)
	{
		len++;
		stack = (stack)->next;
	}
	return (len);
}

void	free_stack(t_stack **stack)
{
	t_stack	*temp;
	t_stack	*current;

	if (stack == NULL)
		return ;
	current = *stack;
	while (current != NULL)
	{
		temp = current->next;
		free(current);
		current = temp;
	}
	*stack = NULL;
}
