/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_file.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lunsold <lunsold@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/06 23:00:48 by lunsold           #+#    #+#             */
/*   Updated: 2026/01/07 00:08:03 by lunsold          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "algo.h"

void start_sort(t_list *stack_a, t_list *stack_b)
{
	while (stack_a->size > 3)
		do_pb(stack_a, stack_b);
	help_sort_three(stack_a);
}
//3 numbers have been sorted in 
//value with best index checker
//now push back from stack b to a the number with the least moves
//until stack b is empty