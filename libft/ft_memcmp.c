/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lunsold <lunsold@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/13 19:02:57 by lunsold           #+#    #+#             */
/*   Updated: 2025/10/20 16:48:37 by lunsold          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned int	i;
	unsigned char	*str1;
	unsigned char	*str2;

	str1 = (unsigned char *)s1;
	str2 = (unsigned char *)s2;
	i = 0;
	while (i < n)
	{
		if (str1[i] != str2[i])
			return (str1[i] - str2[i]);
		i++;
	}
	if (i < n)
	{
		if (str1[i] != str2[i])
			return (str1[i] - str2[i]);
	}
	return (0);
}
// int	main(void)
// {
// 	const char	*s1 = "Hello, World!";
// 	const char	*s2 = "Hello, World!";
// 	size_t		n;
// 	int			result;

// 	n = 13;
// 	result = ft_memcmp(s1, s2, n);
// 	if (result < 0)
// 	{
// 		printf("s1 is less than s2\n");
// 	}
// 	else if (result > 0)
// 	{
// 		printf("s1 is greater than s2\n");
// 	}
// 	else
// 	{
// 		printf("s1 is equal to s2\n");
// 	}
// 	return (0);
// }
