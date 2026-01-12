/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_rrb.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lunsold <lunsold@student.42heilbronn.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/04 22:54:10 by lunsold           #+#    #+#             */
/*   Updated: 2026/01/12 18:38:14 by lunsold          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "swaps.h"

void	do_rrb(t_list *stack_b)
{
	t_node	*shifter;

	if (stack_b->size < 2)
		return ;
	shifter = stack_b->tail;
	stack_b->tail = shifter->prev;
	stack_b->tail->next = NULL;
	shifter->next = stack_b->head;
	shifter->prev = NULL;
	stack_b->head->prev = shifter;
	stack_b->head = shifter;
	write(1, "rrb\n", 4);
}
