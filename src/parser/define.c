/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   define.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lunsold <lunsold@student.42heilbronn.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/09 02:56:55 by lunsold           #+#    #+#             */
/*   Updated: 2026/01/13 11:26:26 by lunsold          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	list_def(t_list *a_list, t_list *b_list)
{
	a_list->head = NULL;
	a_list->tail = NULL;
	a_list->size = 0;
	b_list->head = NULL;
	b_list->tail = NULL;
	b_list->size = 0;
}

t_cost	def_bool(t_cost result, t_bool_flags flags)
{
	result.use_rr = flags.use_rr;
	result.use_rrr = flags.use_rrr;
	result.dir_a_forward = flags.dir_a_forward;
	result.dir_b_forward = flags.dir_b_forward;
	return (result);
}
