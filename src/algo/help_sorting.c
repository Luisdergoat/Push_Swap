/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   help_sorting.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lunsold <lunsold@student.42heilbronn.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/06 23:47:41 by lunsold           #+#    #+#             */
/*   Updated: 2026/01/09 02:51:58 by lunsold          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "algo.h"

int get_index(t_list *stack_b, t_node *element)
{
	t_node *current;
	int counter;

	current = stack_b->head;
	counter = 0;
	while (current)
	{
		if (element->value == current->value)
			return (counter);
		current = current->next;
		counter++;
	}
	return (-1);
}

t_cost calculate_r_rr(t_list *st_a, t_list *st_b, int tar_a, int ind_b, int tmp)
{
	int cost_ra;
	int cost_rra;
	int cost_rb;
	int cost_rrb;
	t_cost result;

	cost_ra = tar_a;
	cost_rra = st_a->size - tar_a;
	cost_rb = ind_b;
	cost_rrb = st_b->size - ind_b;
	tmp = check_options(cost_ra, cost_rb, cost_rra, cost_rrb);
	result = res_check(cost_ra, cost_rb, cost_rra, cost_rrb, tmp);
	return (result);
}

int minook(int cost_a, int cost_b)
{
	if (cost_a > cost_b)
		return (cost_b);
	return (cost_a);
}

t_cost def_result(t_cost result, int cost_a, int cost_b, bool set, int option)
{
	result.moves_a = cost_a;
	result.moves_b = cost_b;
	if (option == 1)
		result = def_bool(result, true, false, true, true);
	if (option == 2)
		result = def_bool(result, false, false, true, false);
	if (option == 3)
		result = def_bool(result, false, false, false, true);
	if (option == 4)
		result = def_bool(result, false, true, false, false);
	return (result);
}

t_cost def_bool(t_cost result, bool u_rr, bool u_rrr, bool dir_a, bool dir_b)
{
	result.use_rr = u_rr;
	result.use_rrr = u_rrr;
	result.dir_a_forward = dir_a;
	result.dir_b_forward = dir_b;
	return (result);
}
