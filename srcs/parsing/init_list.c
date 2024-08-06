/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_list.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbelkace <nbelkace@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 14:16:41 by nbelkace          #+#    #+#             */
/*   Updated: 2024/08/06 07:46:48 by nbelkace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

t_stack	*init_list(t_stack **a, char **argv)
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
		while (split[j])
		{
			temp = init_node(ft_atoi(split[j]));
			if (temp == NULL)
			{
				free_stack(a);
				return (NULL);
			}
			stack_add_back(a, temp);
			j++;
		}
		i++;
	}
	return (*a);
}

t_stack	*init_node(int value)
{
	t_stack	*stack;

	stack = (t_stack *)malloc(sizeof(t_stack));
	if (stack == NULL)
		return (NULL);
	stack->value = value;
	stack->index = -1;
	stack->push_cost_a = 0;
	stack->push_cost_target_b = 0;
	stack->above_median = false;
	stack->cheapest = false;
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

t_stack	*go_end_minus_1(t_stack *end)
{
	if (end == NULL)
		return (end);
	while (end->next->next != NULL)
		end = end->next;
	return (end);
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
