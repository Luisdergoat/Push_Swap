/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_sa.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lunsold <lunsold@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/04 23:04:22 by lunsold           #+#    #+#             */
/*   Updated: 2026/01/12 13:34:23 by lunsold          ###   ########.fr       */
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
