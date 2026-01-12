/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lunsold <lunsold@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/09 02:55:03 by lunsold           #+#    #+#             */
/*   Updated: 2026/01/12 13:34:48 by lunsold          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	add_node_to_stack(t_list *list, int value)
{
	t_node *new_node;

	new_node = create_node(value);
	if (!new_node)
		return ;
	add_node_to_end(list, new_node);
}

t_node	*create_node(int value)
{
	t_node *new_node;

	new_node = malloc(sizeof(t_node));
	if (!new_node)
		return (NULL);
	new_node->next = NULL;
	new_node->prev = NULL;
	new_node->value = (value);
	return (new_node);
}

void	add_node_to_end(t_list *list, t_node *new_node)
{
	if (!list->head)
	{
		list->head = new_node;
		list->tail = new_node;
		new_node->next = NULL;
		new_node->prev = NULL;
		list->size++;
		return ;
	}
	new_node->prev = list->tail;
	new_node->next = NULL;
	list->tail->next = new_node;
	list->tail = new_node;
	list->size++;
}
