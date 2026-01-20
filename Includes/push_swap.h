/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lunsold <lunsold@student.42heilbronn.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/06 10:52:10 by lunsold           #+#    #+#             */
/*   Updated: 2026/01/13 11:26:10 by lunsold          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

//includes
# include "libft.h"
# include "algo.h"
# include "swaps.h"

//library includes
# include <stdlib.h>
# include <stdarg.h>
# include <stddef.h>
# include <stdio.h>
# include <stdbool.h>
# include <unistd.h>
# include <limits.h>

// Forward declarations
typedef struct s_cost		t_cost;
typedef struct s_bool_flags	t_bool_flags;

//linked list def
typedef struct s_node
{
	int				value;
	struct s_node	*next;
	struct s_node	*prev;
}					t_node;

typedef struct s_list
{
	t_node			*head;
	t_node			*tail;
	int				size;
}					t_list;

//function prototypes
int		push_swap(int argc, char **argv);
void	list_def(t_list *a_list, t_list *b_list);
t_node	*create_node(int value);
void	add_node_to_end(t_list *list, t_node *new_node);
void	add_node_to_stack(t_list *list, int value);
int		is_number_str(const char *str);
int		fits_in_int(const char *str);
bool	parse_and_validate(t_list *stack_a, char **args);
bool	is_sorted(t_list *stack);
bool	has_duplicate(t_list *stack_a, int value);
void	free_stack(t_list *stack);
void	free_split(char **split);
t_cost	def_bool(t_cost result, t_bool_flags flags);

#endif