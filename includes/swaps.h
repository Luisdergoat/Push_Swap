/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swaps.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lunsold <lunsold@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/19 07:20:52 by lunsold           #+#    #+#             */
/*   Updated: 2026/01/12 13:36:25 by lunsold          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SWAPS_H
# define SWAPS_H

//includes
# include "push_swap.h"
# include "libft/libft.h"
# include "algo.h"

//function prototypes
void	do_sa(t_list *stack_a);
void	do_sb(t_list *stack_b);
void	do_ss(t_list *stack_a, t_list *stack_b);
void	do_pa(t_list *stack_a, t_list *stack_b);
void	do_pb(t_list *stack_a, t_list *stack_b);
void	do_ra(t_list *stack_a);
void	do_rb(t_list *stack_b);
void	do_rr(t_list *stack_a, t_list *stack_b);
void	do_rra(t_list *stack_a);
void	do_rrb(t_list *stack_b);
void	do_rrr(t_list *stack_a, t_list *stack_b);

//help functions
void	help_pa(t_list *stack_a, t_node *swaper);
void	more_help_pa(t_list *stack_b, t_node *swaper);
void	help_pb(t_list *stack_b, t_node *swaper);
void	more_help_pb(t_list *stack_a, t_node *swaper);

#endif