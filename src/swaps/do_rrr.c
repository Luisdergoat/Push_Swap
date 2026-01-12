/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_rrr.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lunsold <lunsold@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/04 22:53:24 by lunsold           #+#    #+#             */
/*   Updated: 2026/01/12 13:34:19 by lunsold          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "swaps.h"

void	do_rrr(t_list *stack_a, t_list *stack_b)
{
	reverse_rotate_stack_silent(stack_a);
	reverse_rotate_stack_silent(stack_b);
	write(1, "rrr\n", 4);
}
