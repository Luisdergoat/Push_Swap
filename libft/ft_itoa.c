/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lunsold <lunsold@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/20 17:30:22 by lunsold           #+#    #+#             */
/*   Updated: 2025/10/20 17:41:41 by lunsold          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count(int n)
{
	int			i;
	long long	nb;

	i = 1;
	nb = n;
	if (nb < 0)
	{
		i++;
		nb = -nb;
	}
	while (nb > 9)
	{
		nb = (nb / 10);
		i++;
	}
	return (i);
}

char	*ft_itoa(int n)
{
	char		*str;
	long long	nb;
	int			len;

	nb = n;
	len = count(n);
	str = (char *)malloc(sizeof(char) * (len + 1));
	if (!str)
		return (NULL);
	str[len] = '\0';
	if (nb < 0)
	{
		str[0] = '-';
		nb = -nb;
	}
	if (nb == 0)
		str[0] = '0';
	while (nb > 0)
	{
		str[--len] = (nb % 10) + '0';
		nb = nb / 10;
	}
	return (str);
}
// int	main(void)
// {
// 	int		number;
// 	char	*result;

// 	number = -12345;
// 	result = ft_itoa(number);
// 	if (result)
// 	{
// 		printf("String representation of %d is: %s\n", number, result);
// 		free(result);
// 	}
// 	else
// 	{
// 		printf("Failed to allocate memory for string representation.\n");
// 	}
// 	return (0);
// }
