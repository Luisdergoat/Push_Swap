/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotation.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lunsold <lunsold@student.42heilbronn.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/09 02:32:10 by lunsold           #+#    #+#             */
/*   Updated: 2026/01/09 02:39:29 by lunsold          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "algo.h"

t_cost rotate_stacks(t_list *stack_a, t_list *stack_b, t_cost cheapest)
{
	while (cheapest.use_rr && cheapest.moves_a > 0 && cheapest.moves_b > 0)
		cheapest = exe(stack_a, stack_b, cheapest, 1);
	while (cheapest.use_rrr && cheapest.moves_a > 0 && cheapest.moves_b > 0)
		cheapest = exe(stack_a, stack_b, cheapest, 2);
	while (cheapest.moves_a > 0 && cheapest.dir_a_forward)
		cheapest = exe(stack_a, stack_b, cheapest, 3);
	while (cheapest.moves_a > 0 && !cheapest.dir_a_forward)
		cheapest = exe(stack_a, stack_b, cheapest, 4);
	while (cheapest.moves_b > 0 && cheapest.dir_b_forward)
	{
		do_rb(stack_b);
		cheapest.moves_b--;
	}
	while (cheapest.moves_b > 0 && !cheapest.dir_b_forward)
	{
		do_rrb(stack_b);
		cheapest.moves_b--;
	}
	return (cheapest);
}

t_cost exe(t_list *stack_a, t_list *stack_b, t_cost cheapest, int version)
{
	if (version == 1)
	{
		do_rr(stack_a, stack_b);
		cheapest.moves_a--;
		cheapest.moves_b--;
	}
	if (version == 2)
	{
		do_rrr(stack_a, stack_b);
		cheapest.moves_a--;
		cheapest.moves_b--;
	}
	if (version == 3)
	{
		do_ra(stack_a);
		cheapest.moves_a--;
	}
	if (version == 4)
	{
		do_rra(stack_a);
		cheapest.moves_a--;
	}
	
	return (cheapest);
}
