/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   help_swaps.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lunsold <lunsold@student.42heilbronn.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/19 08:24:55 by lunsold           #+#    #+#             */
/*   Updated: 2025/12/19 09:06:27 by lunsold          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "help_swaps.h"

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
