/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lunsold <lunsold@student.42heilbronn.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/16 15:35:05 by lunsold           #+#    #+#             */
/*   Updated: 2026/01/09 03:00:15 by lunsold          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int main(int argc, char **argv)
{
	char *temp;
	int temp_int;
	int counter;

	t_list stack_a;
	t_list stack_b;

	counter = 0;
	if (argc == 1 || (argc == 2 && !argv[1][0]))
		return 0;
	list_def(&stack_a, &stack_b);
	if (argc == 2)
			argv = ft_split(argv[1], ' ');
	while (argv[counter] != 0)
	{
		temp = argv[counter];
		if (!is_number_str(temp) || !fits_in_int(temp))
		{
			ft_putstr_fd("Error\n", 2);
			return 1;
		}
		temp_int = ft_atoi(temp);
		add_node_to_stack(&stack_a, temp_int);
		counter++;
	}
	return (0);
}
