/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_pa.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lunsold <lunsold@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/04 23:00:02 by lunsold           #+#    #+#             */
/*   Updated: 2026/01/04 23:01:20 by lunsold          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "swaps.h"

void do_pa(t_list *stack_a, t_list *stack_b)
{
	t_node *swaper;
	
	if (stack_b->size == 0)
		return ;
	swaper = stack_b->head;
	more_help_pa(stack_b, swaper);
	help_pa(stack_a, swaper);
	write(1, "pa\n", 3);
}

void help_pa(t_list *stack_a, t_node *swaper)
{
	swaper->prev = NULL;
	swaper->next = stack_a->head;
	if (stack_a->size != 0)
	{
		stack_a->head->prev = swaper;
		stack_a->head = swaper;
		stack_a->head->prev = NULL;
	}
	else
	{
		stack_a->tail = swaper;
		stack_a->head = swaper;
		stack_a->head->prev = NULL;
		stack_a->tail->next = NULL;
	}
	stack_a->size++;
}

void more_help_pa(t_list *stack_b, t_node *swaper)
{
	if (stack_b->size == 1)
	{
		stack_b->head = NULL;
		stack_b->tail = NULL;
		stack_b->size--;
	}
	else
	{
		stack_b->head = swaper->next;
		swaper->next = NULL;
		stack_b->head->prev = NULL;
		stack_b->size--;
	}
	if (stack_b->size == 0)
		stack_b->tail = NULL;
}
