/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lunsold <lunsold@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/06 23:16:26 by lunsold           #+#    #+#             */
/*   Updated: 2026/01/07 00:02:44 by lunsold          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ALGO_H
# define ALGO_H

//includes
# include "push_swap.h"
# include "libft/libft.h"
# include "swaps.h"

//function prototypes
void	start_sort(t_list *stack_a, t_list *stack_b);

//help functions
void	help_sort_three(t_list *stack_a);

#endif