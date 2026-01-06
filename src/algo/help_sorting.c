/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   help_sorting.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lunsold <lunsold@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/06 23:47:41 by lunsold           #+#    #+#             */
/*   Updated: 2026/01/07 00:02:09 by lunsold          ###   ########.fr       */
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
