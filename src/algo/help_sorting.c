/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   help_sorting.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lunsold <lunsold@student.42heilbronn.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/06 23:47:41 by lunsold           #+#    #+#             */
/*   Updated: 2026/01/09 01:41:27 by lunsold          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "algo.h"

void help_sort_three(t_list *stack_a)
{	
	int first;
	int second;
	int third;
	int max;

	first = stack_a->head->value;
	second = stack_a->head->next->value;
	third = stack_a->tail->value;
	max = first;
	if(second > max)
		max = second;
	if (third > max)
		max = third;
	if(first == max)
		do_ra(stack_a);
	if (second == max)
		do_rra(stack_a);
	if (stack_a->head->value > stack_a->head->next->value)
        do_sa(stack_a);
}

int find_min_index(t_list *stack_a)
{
	t_node *current;
	int min_value;
	int min_index;
	int index;

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

int	check_options(int cost_ra, int cost_rb, int cost_rra, int cost_rrb)
{
	int option1;
	int option2;
	int option3;
	int option4;
	int min_cost;

	option1 = cost_ra + cost_rb -minook(cost_ra, cost_rb);
	option2 = cost_ra + cost_rrb;
	option3 = cost_rra + cost_rb;
	option4 = cost_rra + cost_rrb - minook(cost_rra, cost_rrb);
	min_cost = minook (minook(option1, option2), minook(option3, option4));
	return (min_cost);
	
}

int minook(int cost_a, int cost_b)
{
	if (cost_a > cost_b)
		return (cost_b);
	return (cost_a);
}

t_cost res_check(int cost_ra, int cost_rb, int cost_rra, int cost_rrb, int min)
{
	t_cost result;
	result.total_cost = min;
	if (min == options_check(cost_ra, cost_rb, cost_rra, cost_rrb, 1))
		result = def_result(result, cost_ra, cost_rb, true, 1);
	else if (min == options_check(cost_ra, cost_rb, cost_rra, cost_rrb, 2))
		result = def_result(result, cost_ra, cost_rrb, false, 2);
	else if (min == options_check(cost_ra, cost_rb, cost_rra, cost_rrb, 3))
		result = def_result(result, cost_rra, cost_rb, false, 3);
	else if (min == options_check(cost_ra, cost_rb, cost_rra, cost_rrb, 4))
		result = def_result(result, cost_rra, cost_rrb, true, 4);
	return (result);
}

int options_check(int cost_ra, int cost_rb, int cost_rra, int cost_rrb, int opt)
{
	int res;

	if (opt == 1)
	{
		res = cost_ra + cost_rb - minook(cost_ra, cost_rb);
		return (res);
	}
	if (opt == 2)
	{
		res = cost_ra + cost_rrb;
		return (res);
	}
	if (opt == 3)
	{
		res = cost_rra + cost_rb;
		return (res);
	}
	if (opt == 4)
	{
		res = cost_rra + cost_rrb - minook(cost_rra, cost_rrb);
		return (res);
	}
	return (-1);
}

t_cost def_result(t_cost result, int cost_a, int cost_b, bool set, int option)
{
	result.moves_a = cost_a;
	result.moves_b = cost_b;
	if (option == 4)
		result.use_rrr = set;
	else
		result.use_rr = set;
	return (result);
}
