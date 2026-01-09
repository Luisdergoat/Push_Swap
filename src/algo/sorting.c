/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lunsold <lunsold@student.42heilbronn.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/06 23:00:48 by lunsold           #+#    #+#             */
/*   Updated: 2026/01/09 01:49:15 by lunsold          ###   ########.fr       */
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
	while (cheapest.moves_a > 0 && cheapest.dir_b_forward)
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

void fastest_rotate(t_list *stack_a)
{
	int min_index;
	int size;
	int cost_forward;
	int cost_reverse;

	min_index = find_min_index(stack_a);
	size = stack_a->size;
	cost_forward = min_index;
	cost_reverse = size - min_index;
	if (cost_forward <= cost_reverse)
	{
		while (min_index-- > 0)
			do_ra(stack_a);
	}
	else
	{
		while (cost_reverse-- > 0)
			do_rra(stack_a);
	}
}
void sort(t_list *stack_a, t_list *stack_b)
{
	t_cost cheapest;
	t_node *current;
	int target_a;
	
	current = stack_b->head;
	while (stack_b->size > 0)
	{
		target_a = find_target_in_a(stack_a, current->value);
		cheapest = find_cheapest_move(stack_a, stack_b);
		if (cheapest.use_rr &&cheapest.moves_a == 0 && cheapest.moves_b == 0)
		{
			do_pa(stack_a, stack_b);
			current = stack_b->head;
		}
		else
			cheapest = rotate_stacks(stack_a, stack_b, cheapest);
		current = current->next;
	}
	if (find_min_index(stack_a) == 0)
		return ;
	else
		fastest_rotate(stack_a);
}
