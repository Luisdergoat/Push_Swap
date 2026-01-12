/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do _rr.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lunsold <lunsold@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/04 23:01:59 by lunsold           #+#    #+#             */
/*   Updated: 2026/01/12 13:33:40 by lunsold          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "swaps.h"

void do_rr(t_list *stack_a, t_list *stack_b)
{
	t_node *shifter;

	if (stack_a->size >= 2)
	{
		shifter = stack_a->head;
		stack_a->head = shifter->next;
		stack_a->head->prev = NULL;
		stack_a->tail->next = shifter;
		shifter->prev = stack_a->tail;
		shifter->next = NULL;
		stack_a->tail = shifter;
	}
	if (stack_b->size >= 2)
	{
		shifter = stack_b->head;
		stack_b->head = shifter->next;
		stack_b->head->prev = NULL;
		stack_b->tail->next = shifter;
		shifter->prev = stack_b->tail;
		shifter->next = NULL;
		stack_b->tail = shifter;
	}
	write(1, "rr\n", 3);
}
