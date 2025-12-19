/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swaps.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lunsold <lunsold@student.42heilbronn.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/19 07:20:52 by lunsold           #+#    #+#             */
/*   Updated: 2025/12/19 09:21:16 by lunsold          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SWAPS_H
# define SWAPS_H

//includes
# include "push_swap.h"
# include <stdlib.h>
# include <stdarg.h>
# include <stddef.h>
# include <stdio.h>
# include <stdbool.h>
# include <unistd.h>
# include <limits.h>
# include "libft/libft.h"

//function prototypes
void	do_sa(t_list *stack_a);
void	do_sb(t_list *stack_b);
void	do_ss(t_list *stack_a, t_list *stack_b);
void	do_pa(t_list *stack_a, t_list *stack_b);
void	do_pb(t_list *stack_a, t_list *stack_b);
void	do_ra(t_list *stack_a);

#endif