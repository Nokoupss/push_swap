/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_list.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbelkace <nbelkace@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 14:16:41 by nbelkace          #+#    #+#             */
/*   Updated: 2024/08/18 23:47:52 by nbelkace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

static long	ft_atol(const char *s) //Define a function that converts every string into a long value
{
	long	result;
	int		sign;

	result = 0;
	sign = 1; 
	while (*s == ' ' || *s == '\t' || *s == '\n' || \
			*s == '\r' || *s == '\f' || *s == '\v')
		s++;
	if (*s == '-' || *s == '+')
	{
		if (*s == '-')
			sign = -1;
		s++;
	}
	while (ft_isdigit(*s))
		result = result * 10 + (*s++ - '0');
	return (result * sign);
}

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
		syntax_error(*a, *split);
		while (split[j])
		{
			temp = init_node(ft_atol(split[j]));
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
