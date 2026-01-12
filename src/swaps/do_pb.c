/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_pb.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lunsold <lunsold@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/04 22:57:46 by lunsold           #+#    #+#             */
/*   Updated: 2026/01/12 13:33:54 by lunsold          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "swaps.h"

void	do_pb(t_list *stack_a, t_list *stack_b)
{
		t_node *swaper;
	
	if (stack_a->size == 0)
		return ;
	swaper = stack_a->head;
	more_help_pb(stack_a, swaper);
	help_pb(stack_b, swaper);
	write(1, "pb\n", 3);
}

void help_pb(t_list *stack_b, t_node *swaper)
{
	swaper->prev = NULL;
	swaper->next = stack_b->head;
	if (stack_b->size != 0)
	{
		stack_b->head->prev = swaper;
		stack_b->head = swaper;
		stack_b->head->prev = NULL;
	}
	else
	{
		stack_b->tail = swaper;
		stack_b->head = swaper;
		stack_b->head->prev = NULL;
		stack_b->tail->next = NULL;
	}
	stack_b->size++;
}

void more_help_pb(t_list *stack_a, t_node *swaper)
{
	if (stack_a->size == 1)
	{
		stack_a->head = NULL;
		stack_a->tail = NULL;
		stack_a->size--;
	}
	else
	{
		stack_a->head = swaper->next;
		swaper->next = NULL;
		stack_a->head->prev = NULL;
		stack_a->size--;
	}
	if (stack_a->size == 0)
		stack_a->tail = NULL;
}
