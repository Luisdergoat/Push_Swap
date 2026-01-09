/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lunsold <lunsold@student.42heilbronn.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/06 23:16:26 by lunsold           #+#    #+#             */
/*   Updated: 2026/01/09 01:55:35 by lunsold          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ALGO_H
# define ALGO_H

//includes
# include "push_swap.h"
# include "libft/libft.h"
# include "swaps.h"
# include <stdbool.h>

//linked list def
typedef struct s_cost
{
	t_node  *element;
	int     value;
	int     index_b;
	int     target_a;
	int     moves_a;
	int     moves_b;
	int     total_cost;
	bool    use_rr;
	bool    use_rrr;
	bool    dir_a_forward;
	bool    dir_b_forward;
}					t_cost;

//function prototypes
void	start_sort(t_list *stack_a, t_list *stack_b);
t_cost	calculate_cost(t_list *stack_a, t_list *stack_b, t_node *element);
int find_target_in_a(t_list *stack_a, int value);

//help functions
void	help_sort_three(t_list *stack_a);
int get_index(t_list *stack_b, t_node *element);
int find_target_in_a(t_list *stack_a, int value);
int min(int cost_a, int cost_b);
int check_options(int cost_ra,int cost_rb,int cost_rra, int cost_rrb);
int options_check(int cost_ra, int cost_rb, int cost_rra, int cost_rrb, int opt);
void def_result(t_cost result, int cost_a, int cost_b, bool set, int option);
t_cost calculate_r_rr(t_list *st_a, t_list *st_b, int tar_a, int ind_b, int tmp);
int find_min_index(t_list *stack_a);


#endif