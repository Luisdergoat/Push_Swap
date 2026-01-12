/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_rrr.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lunsold <lunsold@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/04 22:53:24 by lunsold           #+#    #+#             */
/*   Updated: 2026/01/12 13:34:19 by lunsold          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "swaps.h"

void do_rrr(t_list *stack_a, t_list *stack_b)
{
	t_node *shifter;

	if (stack_a->size >= 2)
	{
		shifter = stack_a->tail;
		stack_a->tail = shifter->prev;
		stack_a->tail->next = NULL;
		shifter->next = stack_a->head;
		shifter->prev = NULL;
		stack_a->head->prev = shifter;
		stack_a->head = shifter;
	}
	if (stack_b->size >= 2)
	{
		shifter = stack_b->tail;
		stack_b->tail = shifter->prev;
		stack_b->tail->next = NULL;
		shifter->next = stack_b->head;
		shifter->prev = NULL;
		stack_b->head->prev = shifter;
		stack_b->head = shifter;
	}
	write(1, "rrr\n", 4);
}
