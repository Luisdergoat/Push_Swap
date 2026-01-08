/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lunsold <lunsold@student.42heilbronn.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/06 23:00:48 by lunsold           #+#    #+#             */
/*   Updated: 2026/01/08 23:59:19 by lunsold          ###   ########.fr       */
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

t_cost find_cheapest_move(t_list *stack_a, t_list *stack_b)
{
	t_node *current;
	t_cost cheapest;
	t_cost cost;

	current = stack_b->head;
	cheapest.total_cost = INT_MAX;
	while (current)
	{
		cost = calculate_cost(stack_a, stack_b, current);
		if (cost.total_cost < cheapest.total_cost)
			cheapest = cost;
		current = current->next;
	}
	return (cheapest);
}
t_cost	calculate_cost(t_list *stack_a, t_list *stack_b, t_node *element)
{
	int index_b;
	int target_a;
	t_cost result;
	
	index_b = get_index(stack_b, element);
	target_a = find_target_in_a(stack_a, element->value);
	result = calculate_r_rr(stack_a, stack_b, target_a, index_b, 0);
	return (result);
}

void sort(t_list *stack_a, t_list *stack_b)
{
	t_cost cheapest;
	t_node *current;

	while (current)
	{
		cheapest = calculate_cost(stack_a, stack_b, current);
		current = current->next;
	}
	
}
//value with best index checker
//now push back from stack b to a the number with the least moves
//until stack b is empty