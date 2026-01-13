/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_funktions.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lunsold <lunsold@student.42heilbronn.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/09 02:47:22 by lunsold           #+#    #+#             */
/*   Updated: 2026/01/12 18:30:59 by lunsold          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "algo.h"

int	check_options(t_rotation rot)
{
	int	option1;
	int	option2;
	int	option3;
	int	option4;
	int	min_cost;

	option1 = rot.ra + rot.rb - minook(rot.ra, rot.rb);
	option2 = rot.ra + rot.rrb;
	option3 = rot.rra + rot.rb;
	option4 = rot.rra + rot.rrb - minook(rot.rra, rot.rrb);
	min_cost = minook(minook(option1, option2), minook(option3, option4));
	return (min_cost);
}

int	options_check(t_rotation rot, int opt)
{
	int	res;

	if (opt == 1)
	{
		res = rot.ra + rot.rb - minook(rot.ra, rot.rb);
		return (res);
	}
	if (opt == 2)
	{
		res = rot.ra + rot.rrb;
		return (res);
	}
	if (opt == 3)
	{
		res = rot.rra + rot.rb;
		return (res);
	}
	if (opt == 4)
	{
		res = rot.rra + rot.rrb - minook(rot.rra, rot.rrb);
		return (res);
	}
	return (-1);
}

t_cost	res_check(t_rotation rot, int min)
{
	t_cost	result;

	result.total_cost = min;
	if (min == options_check(rot, 1))
		result = def_result(result, rot.ra, rot.rb, 1);
	else if (min == options_check(rot, 2))
		result = def_result(result, rot.ra, rot.rrb, 2);
	else if (min == options_check(rot, 3))
		result = def_result(result, rot.rra, rot.rb, 3);
	else if (min == options_check(rot, 4))
		result = def_result(result, rot.rra, rot.rrb, 4);
	return (result);
}
