/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_list.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbelkace <nbelkace@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 14:16:41 by nbelkace          #+#    #+#             */
/*   Updated: 2024/08/15 05:37:54 by nbelkace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

// t_stack	*init_list(t_stack **a, char **argv)
// {
// 	int		i;
// 	int		j;
// 	char	**split;
// 	t_stack	*temp;

// 	i = 1;
// 	while (argv[i] != NULL)
// 	{
// 		j = 0;
// 		split = ft_split(argv[i], ' ');
// 		while (split[j])
// 		{
// 			temp = init_node(ft_atoi(split[j]));
// 			if (temp == NULL)
// 			{
// 				free_stack(a);
// 				return (NULL);
// 			}
// 			stack_add_back(a, temp);
// 			j++;
// 		}
// 		i++;
// 	}
// 	return (*a);
// }

void free_split(char **split)
{
    int i;

    if (split == NULL)
        return;

    i = 0;
    while (split[i] != NULL)
    {
        free(split[i]);
        i++;
    }
    free(split);
}

static void process_split_strings(t_stack **stack, char **split)
{
    int j;
    t_stack *temp;
    int value;

    j = 0;
    while (split[j])
    {
        // Validate syntax
        if (syntax_error(split[j]))
        {
            free_split(split);
            free_stack_error(stack);
        }

        // Convert string to integer and check for duplicate values
        value = ft_atoi(split[j]);
        if (duplicate_error(*stack, value))
        {
            free_split(split);
            free_stack_error(stack);
        }
        // Initialize node and add it to the stack
        temp = init_node(value);
        if (temp == NULL)
        {
            free_split(split);
            free_stack_error(stack);
        }
        stack_add_back(stack, temp);
        j++;
    }
    // Free the split strings
    free_split(split);
}

t_stack *init_list(t_stack **a, char **argv)
{
    int i;
    char **split;

    i = 1;
    while (argv[i] != NULL)
    {
        split = ft_split(argv[i], ' ');
        if (split == NULL) // Check if split failed
        {
            free_stack_error(a);
        }
        process_split_strings(a, split);

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
