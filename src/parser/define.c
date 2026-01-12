/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   define.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lunsold <lunsold@student.42heilbronn.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/09 02:56:55 by lunsold           #+#    #+#             */
/*   Updated: 2026/01/12 18:31:40 by lunsold          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void list_def(t_list *a_list, t_list *b_list)
{
	a_list->head = NULL;
	a_list->tail = NULL;
	a_list->size = 0;
	b_list->head = NULL;
	b_list->tail = NULL;
	b_list->size = 0;
}

t_cost	def_bool(t_cost result, bool u_rr, bool u_rrr, bool dir_a, bool dir_b)
{
	result.use_rr = u_rr;
	result.use_rrr = u_rrr;
	result.dir_a_forward = dir_a;
	result.dir_b_forward = dir_b;
	return (result);
}
