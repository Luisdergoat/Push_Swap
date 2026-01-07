/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lunsold <lunsold@student.42heilbronn.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/06 23:00:48 by lunsold           #+#    #+#             */
/*   Updated: 2026/01/07 10:55:00 by lunsold          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "algo.h"

void start_sort(t_list *stack_a, t_list *stack_b)
{
	while (stack_a->size > 3)
		do_pb(stack_a, stack_b);
	help_sort_three(stack_a);
}
int find_target_in_a(t_list *stack_a, int value)
{
	t_node *current;
	int index;
	int best_value;
	int best_index;

	current = stack_a->head;
	best_index = 0;
	best_value = INT_MAX;
	index = 0;
	while (current)
	{
		if (current->value > value && current->value < best_value)
		{
			best_value = current->value;
			best_index = index;
		}
		current = current->next;
		index++;
	}
	if (best_value == INT_MAX)
		best_index = find_min_index(stack_a);
	return (best_index);
}
//value with best index checker
//now push back from stack b to a the number with the least moves
//until stack b is empty