/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   define.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lunsold <lunsold@student.42heilbronn.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/09 02:56:55 by lunsold           #+#    #+#             */
/*   Updated: 2026/01/09 02:57:20 by lunsold          ###   ########.fr       */
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