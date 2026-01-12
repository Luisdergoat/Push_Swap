/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_funktions.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lunsold <lunsold@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/09 02:47:22 by lunsold           #+#    #+#             */
/*   Updated: 2026/01/12 16:14:28 by lunsold          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "algo.h"

int	check_options(int ra, int rb, int rra, int rrb)
{
	int	option1;
	int	option2;
	int	option3;
	int	option4;
	int	min_cost;

	option1 = ra + rb - minook(ra, rb);
	option2 = ra + rrb;
	option3 = rra + rb;
	option4 = rra + rrb - minook(rra, rrb);
	min_cost = minook(minook(option1, option2), minook(option3, option4));
	return (min_cost);
}

int	options_check(int ra, int rb, int rra, int rrb, int opt)
{
	int	res;

	if (opt == 1)
	{
		res = ra + rb - minook(ra, rb);
		return (res);
	}
	if (opt == 2)
	{
		res = ra + rrb;
		return (res);
	}
	if (opt == 3)
	{
		res = rra + rb;
		return (res);
	}
	if (opt == 4)
	{
		res = rra + rrb - minook(rra, rrb);
		return (res);
	}
	return (-1);
}

t_cost	res_check(int ra, int rb, int rra, int rrb, int min)
{
	t_cost	result;

	result.total_cost = min;
	if (min == options_check(ra, rb, rra, rrb, 1))
		result = def_result(result, ra, rb, 1);
	else if (min == options_check(ra, rb, rra, rrb, 2))
		result = def_result(result, ra, rrb, 2);
	else if (min == options_check(ra, rb, rra, rrb, 3))
		result = def_result(result, rra, rb, 3);
	else if (min == options_check(ra, rb, rra, rrb, 4))
		result = def_result(result, rra, rrb, 4);
	return (result);
}
