/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   help_swaps.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lunsold <lunsold@student.42heilbronn.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/19 08:23:34 by lunsold           #+#    #+#             */
/*   Updated: 2025/12/19 09:07:51 by lunsold          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HELP_SWAPS_H
# define HELP_SWAPS_H

//includes
# include "push_swap.h"
# include "swaps.h"
# include <stdlib.h>
# include <stdarg.h>
# include <stddef.h>
# include <stdio.h>
# include <stdbool.h>
# include <unistd.h>
# include <limits.h>
# include "libft/libft.h"

//function prototypes
void	help_pa(t_list *stack_a, t_node *swaper);
void	more_help_pa(t_list *stack_b, t_node *swaper);
void	help_pb(t_list *stack_b, t_node *swaper);
void	more_help_pb(t_list *stack_a, t_node *swaper);

#endif