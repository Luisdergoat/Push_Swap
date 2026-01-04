/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_ra.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lunsold <lunsold@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/04 22:56:42 by lunsold           #+#    #+#             */
/*   Updated: 2026/01/04 22:56:59 by lunsold          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "swaps.h"

void do_ra(t_list *stack_a)
{
	t_node *shifter;

	if (stack_a->size < 2)
		return ;
	shifter = stack_a->head;
	stack_a->head = shifter->next;
	stack_a->head->prev = NULL;
	stack_a->tail->next = shifter;
	shifter->prev = stack_a->tail;
	shifter->next = NULL;
	stack_a->tail = shifter;
	write(1, "ra\n", 3);
}
