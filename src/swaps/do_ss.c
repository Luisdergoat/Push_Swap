/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_ss.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lunsold <lunsold@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/04 23:02:37 by lunsold           #+#    #+#             */
/*   Updated: 2026/01/12 13:34:32 by lunsold          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "swaps.h"

void	do_ss(t_list *stack_a, t_list *stack_b)
{
	swap_stack_silent(stack_a);
	swap_stack_silent(stack_b);
	write(1, "ss\n", 3);
}
