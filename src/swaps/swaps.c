/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swaps.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lunsold <lunsold@student.42heilbronn.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/19 07:04:01 by lunsold           #+#    #+#             */
/*   Updated: 2025/12/19 09:20:49 by lunsold          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "swaps.h"

void	do_sa(t_list *stack_a)
{
	t_node	*first;
	t_node	*second;
	int		temp;

	if (stack_a->size < 2)
		return ;
	first = stack_a->head;
	second = first->next;
	temp = first->value;
	first->value = second->value;
	second->value = temp;
	write(1, "sa\n", 3);
}

void do_sb(t_list *stack_b)
{
	t_node *first;
	t_node *second;
	int temp;

	if (stack_b->size < 2)
		return ;
	first = stack_b->head;
	second = first->next;
	temp = first->value;
	first->value = second->value;
	second->value = temp;
	write(1, "sb\n", 3);
}
void do_ss(t_list *stack_a, t_list *stack_b)
{
	do_sa(stack_a);
	do_sb(stack_b);
	write(1, "ss\n", 3);
}

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

void	do_pb(t_list *stack_a, t_list *stack_b)
{
		t_node *swaper;
	
	if (stack_b->size == 0)
		return ;
	swaper = stack_b->head;
	more_help_pb(stack_a, swaper);
	help_pb(stack_b, swaper);
	write(1, "pb\n", 3);
}

void do_ra(t_list *stack_a)
{
	t_list *shifter;

	if (stack_a->size == 0)
		return ;
	shifter = stack_a->head;
	
	
}