/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   silent_operations.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lunsold <lunsold@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/12 18:00:00 by lunsold           #+#    #+#             */
/*   Updated: 2026/01/12 18:00:00 by lunsold          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "swaps.h"

void	rotate_stack_silent(t_list *stack)
{
	t_node	*shifter;

	if (stack->size < 2)
		return ;
	shifter = stack->head;
	stack->head = shifter->next;
	stack->head->prev = NULL;
	stack->tail->next = shifter;
	shifter->prev = stack->tail;
	shifter->next = NULL;
	stack->tail = shifter;
}

void	reverse_rotate_stack_silent(t_list *stack)
{
	t_node	*shifter;

	if (stack->size < 2)
		return ;
	shifter = stack->tail;
	stack->tail = shifter->prev;
	stack->tail->next = NULL;
	shifter->next = stack->head;
	shifter->prev = NULL;
	stack->head->prev = shifter;
	stack->head = shifter;
}

void	swap_stack_silent(t_list *stack)
{
	t_node	*first;
	t_node	*second;
	int		temp;

	if (stack->size < 2)
		return ;
	first = stack->head;
	second = first->next;
	temp = first->value;
	first->value = second->value;
	second->value = temp;
}
