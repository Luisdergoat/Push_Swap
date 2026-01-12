/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_rb.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lunsold <lunsold@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/04 22:55:17 by lunsold           #+#    #+#             */
/*   Updated: 2026/01/12 13:34:04 by lunsold          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "swaps.h"

void do_rb(t_list *stack_b)
{
	t_node *shifter;
	
	if (stack_b->size < 2)
		return ;
	shifter =stack_b->head;
	stack_b->head =shifter->next;
	stack_b->head->prev = NULL;
	stack_b->tail->next = shifter;
	shifter->prev = stack_b->tail;
	shifter->next = NULL;
	stack_b->tail = shifter;
	write(1, "rb\n", 3);
}
