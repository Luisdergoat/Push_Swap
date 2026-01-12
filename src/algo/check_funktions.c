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

int	check_options(int cost_ra, int cost_rb, int cost_rra, int cost_rrb)
{
	int option1;
	int option2;
	int option3;
	int option4;
	int min_cost;

	option1 = cost_ra + cost_rb -minook(cost_ra, cost_rb);
	option2 = cost_ra + cost_rrb;
	option3 = cost_rra + cost_rb;
	option4 = cost_rra + cost_rrb - minook(cost_rra, cost_rrb);
	min_cost = minook (minook(option1, option2), minook(option3, option4));
	return (min_cost);
	
}

int options_check(int cost_ra, int cost_rb, int cost_rra, int cost_rrb, int opt)
{
	int res;

	if (opt == 1)
	{
		res = cost_ra + cost_rb - minook(cost_ra, cost_rb);
		return (res);
	}
	if (opt == 2)
	{
		res = cost_ra + cost_rrb;
		return (res);
	}
	if (opt == 3)
	{
		res = cost_rra + cost_rb;
		return (res);
	}
	if (opt == 4)
	{
		res = cost_rra + cost_rrb - minook(cost_rra, cost_rrb);
		return (res);
	}
	return (-1);
}

t_cost res_check(int cost_ra, int cost_rb, int cost_rra, int cost_rrb, int min)
{
	t_cost result;
	result.total_cost = min;
	if (min == options_check(cost_ra, cost_rb, cost_rra, cost_rrb, 1))
		result = def_result(result, cost_ra, cost_rb, 1);
	else if (min == options_check(cost_ra, cost_rb, cost_rra, cost_rrb, 2))
		result = def_result(result, cost_ra, cost_rrb, 2);
	else if (min == options_check(cost_ra, cost_rb, cost_rra, cost_rrb, 3))
		result = def_result(result, cost_rra, cost_rb, 3);
	else if (min == options_check(cost_ra, cost_rb, cost_rra, cost_rrb, 4))
		result = def_result(result, cost_rra, cost_rrb, 4);
	return (result);
}
