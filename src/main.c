/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lunsold <lunsold@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/16 15:35:05 by lunsold           #+#    #+#             */
/*   Updated: 2026/01/12 18:30:00 by lunsold          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static char	**parse_arguments(int argc, char **argv, bool *need_free)
{
	char	**args;

	*need_free = false;
	if (argc == 2)
	{
		args = ft_split(argv[1], ' ');
		*need_free = true;
		if (!args || !args[0])
		{
			free_split(args);
			return (NULL);
		}
	}
	else
		args = argv + 1;
	return (args);
}

static int	validate_and_parse(t_list *stack_a, char **args, bool need_free)
{
	if (!parse_and_validate(stack_a, args))
	{
		if (need_free)
			free_split(args);
		free_stack(stack_a);
		ft_putstr_fd("Error\n", 2);
		return (1);
	}
	if (need_free)
		free_split(args);
	return (0);
}

static void	execute_sort(t_list *stack_a, t_list *stack_b)
{
	if (stack_a->size == 2)
		sort_two(stack_a);
	else if (stack_a->size == 3)
		help_sort_three(stack_a);
	else
	{
		start_sort(stack_a, stack_b);
		sort(stack_a, stack_b);
	}
}

int	main(int argc, char **argv)
{
	t_list	stack_a;
	t_list	stack_b;
	char	**args;
	bool	need_free;

	if (argc < 2)
		return (0);
	list_def(&stack_a, &stack_b);
	args = parse_arguments(argc, argv, &need_free);
	if (!args)
		return (0);
	if (validate_and_parse(&stack_a, args, need_free))
		return (1);
	if (is_sorted(&stack_a) || stack_a.size == 0)
	{
		free_stack(&stack_a);
		return (0);
	}
	execute_sort(&stack_a, &stack_b);
	free_stack(&stack_a);
	free_stack(&stack_b);
	return (0);
}
