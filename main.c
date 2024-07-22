/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbelkace <nbelkace@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 15:54:23 by nbelkace          #+#    #+#             */
/*   Updated: 2024/06/07 18:17:48 by nbelkace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/push_swap.h"

int	main(int argc, char **argv)
{
	t_stack	*a;
	t_stack	*b;

	a = NULL;
	b = NULL;
	if ((argc == 1) || (argc == 2 && argv[1][0] == 0))
		return (1);
	else if (argc >= 2)
		init_list(a, argv);
	return (0);
}
