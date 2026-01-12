/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_rra.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lunsold <lunsold@student.42heilbronn.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/04 22:51:47 by lunsold           #+#    #+#             */
/*   Updated: 2026/01/12 18:37:58 by lunsold          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "swaps.h"

void	do_rra(t_list *stack_a)
{
	t_node	*shifter;

	if (stack_a->size < 2)
		return ;
	shifter = stack_a->tail;
	stack_a->tail = shifter->prev;
	stack_a->tail->next = NULL;
	shifter->next = stack_a->head;
	shifter->prev = NULL;
	stack_a->head->prev = shifter;
	stack_a->head = shifter;
	write(1, "rra\n", 4);
}
