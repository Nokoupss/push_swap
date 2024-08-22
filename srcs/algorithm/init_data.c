/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbelkace <nbelkace@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/30 06:08:34 by nbelkace          #+#    #+#             */
/*   Updated: 2024/08/22 04:30:04 by nbelkace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

t_stack	*init_data_a(t_stack *a, t_stack *b)
{
	set_index(a);
	set_index(b);
	set_target_node_a(a, b);
	cost_analysis_a(a);
	cost_analysis_b(b);
	return (set_cheapest_a(a));
}

t_stack	*init_data_b(t_stack *a, t_stack *b)
{
	set_index(a);
	set_index(b);
	set_target_node_a(a, b);
	set_target_node_b(a, b);
	cost_analysis_a(a);
	cost_analysis_b(b);
	return (set_cheapest_b(b));
}
