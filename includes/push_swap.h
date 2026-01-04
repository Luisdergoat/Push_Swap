/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lunsold <lunsold@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/06 10:52:10 by lunsold           #+#    #+#             */
/*   Updated: 2026/01/04 22:39:42 by lunsold          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

//includes
# include <stdarg.h>
# include <stddef.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <limits.h>
# include "libft/libft.h"

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

#endif