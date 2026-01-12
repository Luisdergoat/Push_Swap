/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lunsold <lunsold@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/12 11:47:25 by lunsold           #+#    #+#             */
/*   Updated: 2026/01/12 13:35:03 by lunsold          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

bool has_duplicate(t_list *stack_a, int value)
{
	t_node *current;
	
	current = stack_a->head;
	while (current)
	{
		if (current->value == value)
			return (true);
		current = current->next;		
	}
	return (false);
}

bool is_sorted(t_list *stack)
{
	t_node *current;
	if ((stack->size <= 1))
		return (true);
	current = stack->head;
	while (current->next)
	{
		if (current->value > current->next->value)
			return (false);
		current = current->next;
	}
	return (true);
}

bool parse_and_validate(t_list *stack_a, char **args)
{
	int i;
	int value;
	
	i = 0;
	while (args[i])
	{
		if (!is_number_str(args[i]))
			return (false);
		if (!fits_in_int(args[i]))
			return (false);
		value = ft_atoi(args[i]);
		if (has_duplicate(stack_a, value))
			return (false);
		add_node_to_stack(stack_a, value);
		i++;
	}
	return (true);
}
