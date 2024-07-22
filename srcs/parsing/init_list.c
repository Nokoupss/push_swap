/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_struct.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbelkace <nbelkace@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 14:16:41 by nbelkace          #+#    #+#             */
/*   Updated: 2024/04/25 13:56:51 by nbelkace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*init_list(t_stack *a, char **argv)
{
	int		i;
	int		j;
	char	**split;
	t_stack	*temp;

	i = 0;
	while (argv[i] != '\0')
	{
		j = 0;
		split = ft_split(argv[i], ' ');
		while (split[j])
		{
			temp = init_node(ft_atoi(split[j]));
			if (temp == NULL)
			{
				free_list(a);
				return (NULL);
			}
			stack_add_back(&a, temp);
			j++;
		}
		i++;
	}
	return (a);
}

t_stack	*init_node(int value)
{
	t_stack	*stack;

	stack = (t_stack *)malloc(sizeof(t_stack));
	if (stack == NULL)
		return (NULL);
	stack->value = value;
	stack->next = NULL;
	return (stack);
}

t_stack	*stack_last(t_stack *stack)
{
	t_stack	*temp;

	temp = stack;
	if (stack == NULL)
		return (NULL);
	while (temp->next != NULL)
		temp = temp->next;
	return (temp);
}

void	stack_add_back(t_stack **stack, t_stack *new)
{
	t_stack	*last;

	if (stack == NULL)
		return ;
	if (*stack == NULL)
	{
		*stack = new;
		return ;
	}
	last = stack_last(*stack);
	last->next = new;
}
