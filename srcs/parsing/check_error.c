/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbelkace <nbelkace@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/18 19:57:59 by nbelkace          #+#    #+#             */
/*   Updated: 2024/08/22 04:37:28 by nbelkace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	overflow_error(t_stack *a)
{
	long	n;

	n = 0;
	if (a == NULL)
		return ;
	while (a != NULL)
	{
		n = a->value;
		if (n > INT_MAX || n < INT_MIN)
			free_stack_error(&a);
		a = a->next;
	}
}

void	duplicate_error(t_stack *a)
{
	t_stack	*current;
	t_stack	*compare;

	if (a == NULL)
		return ;
	current = a;
	while (current != NULL)
	{
		compare = current->next;
		while (compare != NULL)
		{
			if (current->value == compare->value)
			{
				free_stack_error(&a);
				return ;
			}
			compare = compare->next;
		}
		current = current->next;
	}
}

void	syntax_error(t_stack *a, char **split, int i)
{
	int	j;

	j = 0;
	if ((split[i][j] != '+' && split[i][j] != '-')
		&& (split[i][j] < '0' || split[i][j] > '9'))
	{
		free_split(split);
		free_stack_error(&a);
	}
	if ((split[i][j] == '+' || split[i][j] == '-')
		&& (split[i][j + 1] < '0' || split[i][j + 1] > '9'))
	{
		free_split(split);
		free_stack_error(&a);
	}
	j++;
	while (split[i][j] != '\0')
	{
		if (split[i][j] < '0' || split[i][j] > '9')
		{
			free_split(split);
			free_stack_error(&a);
		}
		j++;
	}
}

void	free_stack_error(t_stack **stack)
{
	free_stack(stack);
	write(2, "Error\n", 5);
	exit(1);
}
