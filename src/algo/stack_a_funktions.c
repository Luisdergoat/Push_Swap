/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_a_funktions.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lunsold <lunsold@student.42heilbronn.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/09 02:29:36 by lunsold           #+#    #+#             */
/*   Updated: 2026/01/12 18:31:25 by lunsold          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "algo.h"

void	help_sort_three(t_list *stack_a)
{
	int	first;
	int	second;
	int	third;
	int	max;

	first = stack_a->head->value;
	second = stack_a->head->next->value;
	third = stack_a->tail->value;
	max = first;
	if (second > max)
		max = second;
	if (third > max)
		max = third;
	if (first == max)
		do_ra(stack_a);
	else if (second == max)
		do_rra(stack_a);
	if (stack_a->head->value > stack_a->head->next->value)
		do_sa(stack_a);
}

int	find_min_index(t_list *stack_a)
{
	t_node	*current;
	int		min_value;
	int		min_index;
	int		index;

	min_index = 0;
	index = 0;
	current = stack_a->head;
	min_value = current->value;
	while (current)
	{
		if (current->value < min_value)
		{
			min_value = current->value;
			min_index = index;
		}
		current = current->next;
		index++;
	}
	return (min_index);
}

void	fastest_rotate(t_list *stack_a)
{
	int	min_index;
	int	rotations;

	min_index = find_min_index(stack_a);
	if (min_index == 0)
		return ;
	if (min_index <= stack_a->size - min_index)
	{
		rotations = 0;
		while (rotations < min_index)
		{
			do_ra(stack_a);
			rotations++;
		}
	}
	else
	{
		rotations = 0;
		while (rotations < stack_a->size - min_index)
		{
			do_rra(stack_a);
			rotations++;
		}
	}
}

int	find_target_in_a(t_list *stack_a, int value)
{
	t_node	*current;
	int		index;
	int		best_value;
	int		best_index;

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
