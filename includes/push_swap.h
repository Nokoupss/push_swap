/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbelkace <nbelkace@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 15:55:08 by nbelkace          #+#    #+#             */
/*   Updated: 2024/06/07 18:03:38 by nbelkace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../srcs/utils/libft/libft.h"
# include <stdlib.h>
# include <stdbool.h>
# include <limits.h>
# include <unistd.h>

typedef struct s_stack
{
	int				value;
	int				index;
	int				push_cost;
	struct s_stack	*next;
	struct s_stack	*prev;
}				t_stack;

/*
**Command
*/
/*
**push_command
*/

void	push(t_stack **src, t_stack **dest);
void	pa(t_stack **stack_b, t_stack **stack_a);
void	pb(t_stack **stack_a, t_stack **stack_b);

/*
**Command
*/
/*
**reverse-rotate_command
*/

void	reverse_rotate(t_stack **stack);
void	rra(t_stack **stack_a);
void	rrb(t_stack **stack_b);
void	rrr(t_stack **stack_a, t_stack **stack_b);

/*
**Command
*/
/*
**rotate_command
*/

void	rotate(t_stack **stack);
void	ra(t_stack **stack_a);
void	rb(t_stack **stack_b);
void	rr(t_stack **stack_a, t_stack **stack_b);

/*
**Command
*/
/*
**swap_command
*/

void	swap(t_stack **stack);
void	sa(t_stack **stack_a);
void	sb(t_stack **stack_b);
void	ss(t_stack **stack_a, t_stack **stack_b);

/*
**Parsing
*/
/*
**init_list
*/

t_stack	*init_list(t_stack *a, char **argv);
t_stack	*init_node(int value);
t_stack	*stack_last(t_stack *stack);
void	stack_add_back(t_stack **stack, t_stack *new);

#endif