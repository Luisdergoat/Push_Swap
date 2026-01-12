/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lunsold <lunsold@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/06 23:00:48 by lunsold           #+#    #+#             */
/*   Updated: 2026/01/12 18:07:31 by lunsold          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "algo.h"

void	start_sort(t_list *stack_a, t_list *stack_b)
{
	while (stack_a->size > 3)
		do_pb(stack_a, stack_b);
	help_sort_three(stack_a);
}

t_cost	find_cheapest_move(t_list *stack_a, t_list *stack_b)
{
	t_node	*current;
	t_cost	cheapest;
	t_cost	cost;

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
	int		index_b;
	int		target_a;
	t_cost	result;

	index_b = get_index(stack_b, element);
	target_a = find_target_in_a(stack_a, element->value);
	result = calculate_r_rr(stack_a, stack_b, target_a, index_b, 0);
	return (result);
}

void	sort(t_list *stack_a, t_list *stack_b)
{
	t_cost	cheapest;

	while (stack_b->size > 0)
	{
		cheapest = find_cheapest_move(stack_a, stack_b);
		if (cheapest.moves_a == 0 && cheapest.moves_b == 0)
			do_pa(stack_a, stack_b);
		else
		{
			rotate_stacks(stack_a, stack_b, cheapest);
			do_pa(stack_a, stack_b);
		}
	}
	if (find_min_index(stack_a) != 0)
		fastest_rotate(stack_a);
}

void	sort_two(t_list *stack_a)
{
	if (stack_a->head->value > stack_a->head->next->value)
		do_sa(stack_a);
}
