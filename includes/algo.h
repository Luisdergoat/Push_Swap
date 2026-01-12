/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lunsold <lunsold@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/06 23:16:26 by lunsold           #+#    #+#             */
/*   Updated: 2026/01/12 16:12:39 by lunsold          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ALGO_H
# define ALGO_H

// Forward declarations
typedef struct s_node t_node;
typedef struct s_list t_list;

//includes
# include "push_swap.h"
# include "libft.h"
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
t_cost	find_cheapest_move(t_list *stack_a, t_list *stack_b);
t_cost	calculate_cost(t_list *stack_a, t_list *stack_b, t_node *element);
void	sort(t_list *stack_a, t_list *stack_b);
void sort_two(t_list *stack_a);

//help functions
int		get_index(t_list *stack_b, t_node *element);
t_cost	calculate_r_rr(t_list *st_a, t_list *st_b, int tar_a, int ind_b, int tmp);
int		minook(int cost_a, int cost_b);
t_cost	def_result(t_cost result, int cost_a, int cost_b, int option);
t_cost	rotate_stacks(t_list *stack_a, t_list *stack_b, t_cost cheapest);
t_cost	exe(t_list *stack_a, t_list *stack_b, t_cost cheapest, int version);
int		find_target_in_a(t_list *stack_a, int value);
void	help_sort_three(t_list *stack_a);
int		find_min_index(t_list *stack_a);
void	fastest_rotate(t_list *stack_a);
t_cost	res_check(int cost_ra, int cost_rb, int cost_rra, int cost_rrb, int min);
int		check_options(int cost_ra, int cost_rb, int cost_rra, int cost_rrb);
int		options_check(int cost_ra, int cost_rb, int cost_rra, int cost_rrb, int opt);

#endif