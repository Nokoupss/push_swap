/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbelkace <nbelkace@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 15:55:08 by nbelkace          #+#    #+#             */
/*   Updated: 2024/08/08 07:34:43 by nbelkace         ###   ########.fr       */
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
	int				push_cost_a;
	int				push_cost_b;
	bool			above_median;
	struct s_stack	*next;
	struct s_stack	*target_node;
}				t_stack;

void	print_stack(t_stack *stack);
t_stack	*go_end_minus_1(t_stack *end);

void	rotate_both_stacks_test(t_stack **b, t_stack **a);
void	reverse_rotate_both_stacks_test(t_stack **b, t_stack **a);
void	rotate_stack_b_test(t_stack **b, int push_cost_b);
void	rotate_stack_a_test(t_stack **a, int push_cost_a);
void	rotate_all_test(t_stack **b, t_stack **a, t_stack *cheapest_node);

/*
**Algorithm
*/
/*
**algo_rotate
*/

void	rotate_both_stacks(t_stack **a, t_stack **b);
void	reverse_rotate_both_stacks(t_stack **a, t_stack **b);
void	rotate_stack_a(t_stack **a, int push_cost_a);
void	rotate_stack_b(t_stack **b, int push_cost_b);
void	rotate_all(t_stack **a, t_stack **b, t_stack *cheapest_node);

/*
**Algorithm
*/
/*
**algo_utils
*/

t_stack	*find_max_node(t_stack *stack);
t_stack	*find_min_node(t_stack *stack);
int		ft_abs(int nb);
int		find_min_value(t_stack **a);
void	min_on_top(t_stack **a);

/*
**Algorithm
*/
/*
**cost_analysis
*/

void	set_index(t_stack *stack);
void	cost_analysis_a(t_stack *a);
void	cost_analysis_b(t_stack *b);
long	calculate_total_cost(t_stack *stack);
t_stack	*set_cheapest(t_stack *stack);
long	calculate_total_cost_b_to_a(t_stack *b);
t_stack	*set_cheapest_b_to_a(t_stack *b);
/*
**Algorithm
*/
/*
**init_data
*/

t_stack	*init_data_a(t_stack *a, t_stack *b);
t_stack	*init_data_b(t_stack *a, t_stack *b);

/*
**Algorithm
*/
/*
**set_target_node
*/

void	push_2_to_b(t_stack **a, t_stack **b);
t_stack	*find_closest_smaller(t_stack *b, int value);
void	set_target_node_a(t_stack *a, t_stack *b);
t_stack	*find_closest_bigger(t_stack *a, int value);
void	set_target_node_b(t_stack *b, t_stack *a);

/*
**Algorithm
*/
/*
**sort_stacks
*/

void	sort_stacks(t_stack **a, t_stack **b);

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

void	swap(t_stack **head);
void	sa(t_stack **stack_a);
void	sb(t_stack **stack_b);
void	ss(t_stack **stack_a, t_stack **stack_b);

/*
**Parsing
*/
/*
**init_list
*/

t_stack	*init_list(t_stack **a, char **argv);
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
void	free_stack(t_stack **stack);

#endif