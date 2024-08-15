/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbelkace <nbelkace@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/25 03:44:10 by nbelkace          #+#    #+#             */
/*   Updated: 2024/08/15 03:41:23 by nbelkace         ###   ########.fr       */
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

int	duplicate_error(t_stack *a, int n)
{
	if (a == NULL)
		return (0);
	while (a != NULL)
	{
		if (a->value == n)
			return (1);
		a = a->next;
	}
	return (0);
}

int	syntax_error(char *str_n)
{
	int	i;

	i = 0;
	if ((str_n[i] != '+' && str_n[i] != '-') 
		&& (str_n[i] < '0' || str_n[i] > '9'))
		return (1);
	if ((str_n[i] == '+' || str_n[i] == '-') 
		&& (str_n[i + 1] < '0' || str_n[i + 1] > '9'))
		return (1);
	i++;
	while (str_n[i] != '\0')
	{
		if (str_n[i] < '0' || str_n[i] > '9')
			return (1);
		i++;
	}
	return (0);
}

void	free_stack_error(t_stack **stack)
{
	free_stack(stack);
	write(2, "Error\n", 5);
	exit(1);
}
