/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do _rr.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lunsold <lunsold@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/04 23:01:59 by lunsold           #+#    #+#             */
/*   Updated: 2026/01/12 13:33:40 by lunsold          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "swaps.h"

void	do_rr(t_list *stack_a, t_list *stack_b)
{
	rotate_stack_silent(stack_a);
	rotate_stack_silent(stack_b);
	write(1, "rr\n", 3);
}
