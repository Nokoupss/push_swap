/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbelkace <nbelkace@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 15:54:23 by nbelkace          #+#    #+#             */
/*   Updated: 2024/08/08 07:56:41 by nbelkace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/push_swap.h"

void	print_stack(t_stack *stack)
{
	while (stack)
	{
		ft_printf("%d ", stack->value);
		stack = stack->next;
	}
	ft_printf("\n");
}

int	main(int argc, char **argv)
{
	t_stack	*a;
	t_stack	*b;

	a = NULL;
	b = NULL;
	if ((argc == 1) || (argc == 2 && argv[1][0] == 0))
		return (1);
	else if (argc >= 2)
		init_list(&a, argv);
	ft_printf("Initial stack:\n");
	print_stack(a);
	if (is_sorted(a) == false)
	{
		if (stack_len(a) == 2)
			sa(&a);
		else if (stack_len(a) == 3)
			sort_three(&a);
		else
			sort_stacks(&a, &b);
	}
	ft_printf("Sorted stack:\n");
	print_stack(a);
	print_stack(b);
	free_stack(&a);
	free_stack(&b);
	return (0);
}
