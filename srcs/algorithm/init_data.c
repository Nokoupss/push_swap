/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbelkace <nbelkace@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/30 06:08:34 by nbelkace          #+#    #+#             */
/*   Updated: 2024/08/06 05:51:54 by nbelkace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	init_data_a(t_stack *a, t_stack *b)
{
	set_index(a);
	set_index(b);
	set_target_node_a(a, b);
	cost_analysis_a(a);
	cost_analysis_target_b(b);
	set_cheapest(a);
}

void	init_data_b(t_stack *a, t_stack *b)
{
	set_index(a);
	set_index(b);
	set_target_node_a(a, b);
	set_target_node_b(a, b);
	cost_analysis_a(a);
	cost_analysis_target_b(b);
	set_cheapest(b);
}
