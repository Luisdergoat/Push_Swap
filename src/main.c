/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lunsold <lunsold@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/16 15:35:05 by lunsold           #+#    #+#             */
/*   Updated: 2026/01/12 12:02:30 by lunsold          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int main(int argc, char **argv)
{
	t_list stack_a;
	t_list stack_b;
	char **args;
	int i;
	bool need_free;

	if (argc < 2)
		return (0);
	list_def(&stack_a, &stack_b);
	need_free = false;
	if (argc = 2)
	{
		args = ft_split(argv[1], ' ');
		need_free = true;
		if (!args || !args[0])
		{
			free_split(args);
			return (0);
		}
	}
	else 
		args = argv + 1;
	if (! parse_and_validate(&stack_a, args))
	{
		if (need_free)
			free_splitt(args);
		free_stack(&stack_a);
		ft_putstr_fd("Error\n", 2);
		return (1);
	}
	if (need_free)
		free_splitt(args);
	if (stack_a.size == 2)
		sort_two(stack_a);
	else if (stack_a.size == 3)
		help_sort_three(&stack_a);
	else
	{
		start_sort(&stack_a, &stack_b);
		sort(&stack_a, &stack_b);
	}
	free_stack(&stack_a);
	free_stack(&stack_b);
	
	return (0);
}
