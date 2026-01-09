/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lunsold <lunsold@student.42heilbronn.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/16 15:35:05 by lunsold           #+#    #+#             */
/*   Updated: 2026/01/09 01:55:14 by lunsold          ###   ########.fr       */
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

void	add_node_to_stack(t_list *list, int value)
{
	t_node *new_node;

	new_node = create_node(value);
	if (!new_node)
		return ;
	add_node_to_end(list, new_node);
}

int is_number_str(const char *str)
{
	int i;

	i = 0;
	if (!str || !str[0])
		return 0;
	if (str[i] == '+' || str[i] == '-')
		i++;
	if (!str[i])
		return 0;
	while (str[i])
	{
		if (str[i] < '0' || str[i] > '9')
			return 0;
		i++;
	}
	return 1;
}

int fits_in_int(const char *str)
{
	long long n;
	int sign;

	n = 0;
	sign = 1;
	if (*str == '+' || *str == '-')
	{	
		ft_putchar_fd("Error\n", 2);
		if (*str == '-')
			sign = -1;
		str++;
	}
	while (*str)
	{
		  n = n * 10 + (*str - '0');
        if (sign == 1 && n > 2147483647LL)
            return 0;
        if (sign == -1 && -n < -2147483648LL)
            return 0;
        str++;
	}
	return 1;
}

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
