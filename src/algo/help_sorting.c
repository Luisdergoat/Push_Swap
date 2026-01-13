/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   help_sorting.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lunsold <lunsold@student.42heilbronn.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/06 23:47:41 by lunsold           #+#    #+#             */
/*   Updated: 2026/01/12 18:39:07 by lunsold          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "algo.h"

int	get_index(t_list *stack_b, t_node *element)
{
	t_node	*current;
	int		counter;

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

t_cost	calculate_r_rr(t_list *a, t_list *b, int ta, int ib)
{
	t_rotation	rot;
	int			min;
	t_cost		result;

	rot.ra = ta;
	rot.rra = a->size - ta;
	rot.rb = ib;
	rot.rrb = b->size - ib;
	min = check_options(rot);
	result = res_check(rot, min);
	return (result);
}

int	minook(int cost_a, int cost_b)
{
	if (cost_a > cost_b)
		return (cost_b);
	return (cost_a);
}

t_cost	def_result(t_cost result, int cost_a, int cost_b, int option)
{
	t_bool_flags	flags;

	result.moves_a = cost_a;
	result.moves_b = cost_b;
	if (option == 1)
		flags = (t_bool_flags){true, false, true, true};
	if (option == 2)
		flags = (t_bool_flags){false, false, true, false};
	if (option == 3)
		flags = (t_bool_flags){false, false, false, true};
	if (option == 4)
		flags = (t_bool_flags){false, true, false, false};
	result = def_bool(result, flags);
	return (result);
}
