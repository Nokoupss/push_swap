/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_list.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbelkace <nbelkace@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 14:16:41 by nbelkace          #+#    #+#             */
/*   Updated: 2024/08/22 03:17:21 by nbelkace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	init_list(t_stack **a, char **argv)
{
	int		i;
	int		j;
	char	**split;
	t_stack	*temp;

	i = 1;
	while (argv[i] != NULL)
	{
		j = 0;
		split = ft_split(argv[i], ' ');
		if (split == NULL)
			return ;
		while (split[j] != NULL)
		{
			syntax_error(*a, split, j);
			temp = init_node(ft_atol(split[j]));
			if (temp == NULL)
				free_stack_split(a, split);
			stack_add_back(a, temp);
			j++;
		}
		free_split(split);
		i++;
	}
}

t_stack	*init_node(long value)
{
	t_stack	*stack;

	stack = (t_stack *)malloc(sizeof(t_stack));
	if (stack == NULL)
		return (NULL);
	stack->value = value;
	stack->index = -1;
	stack->push_cost_a = 0;
	stack->push_cost_b = 0;
	stack->above_median = false;
	stack->next = NULL;
	stack->target_node = NULL;
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
