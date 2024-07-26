/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbelkace <nbelkace@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 15:55:08 by nbelkace          #+#    #+#             */
/*   Updated: 2024/07/26 05:27:51 by nbelkace         ###   ########.fr       */
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
	struct s_stack	*target_node;
}				t_stack;

/*
**Algorithm
*/
/*
**set_target_node
*/

void	push_a_to_b(t_stack **a, t_stack **b);
t_stack	*find_closest_smaller(t_stack *b, int value);
void	set_target_node_a(t_stack *a, t_stack *b);

/*
**Algorithm
*/
/*
**sort_three
*/

void	sort_three(t_stack **a);

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

/*
**Parsing
*/
/*
**stack_utils
*/

int		is_sorted(t_stack *stack);
int		stack_len(t_stack *stack);
t_stack	*find_max_node(t_stack *stack);
t_stack	*find_min_node(t_stack *stack);
void	free_list(t_stack *stack);

#endif