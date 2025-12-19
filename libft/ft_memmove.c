/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lunsold <lunsold@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/08 21:18:26 by lunsold           #+#    #+#             */
/*   Updated: 2025/10/20 17:27:00 by lunsold          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t	i;

	i = 0;
	if (len == 0 || dst == src)
		return (dst);
	if (dst < src)
	{
		while (i < len)
		{
			((unsigned char *)dst)[i] = ((unsigned char *)src)[i];
			i++;
		}
	}
	else
	{
		i = len;
		while (i > 0)
		{
			i--;
			((unsigned char *)dst)[i] = ((unsigned char *)src)[i];
		}
	}
	return (dst);
}
// #include <stdio.h>
// #include <string.h>

// int	main(void)
// {
// 	char	src[] = "Hello, World!";
// 	char	dst[20];
// 	char	buffer[20] = "1234567890";

// 	// Beispiel 1: Normale Kopie
// 	// ft_memmove(dst, src, 5);
// 	// printf("dst nach memmove: %s\n", dst);
// 	// Beispiel 2: Überlappende Bereiche (src < dst)
// 	// ft_memmove(buffer + 5, buffer, 10);
// 	// printf("Überlappung (src < dst): %s\n", buffer);
// 	// // Beispiel 3: Überlappende Bereiche (dst < src)
// 	// strcpy(buffer, "abcdefghij");
// 	// ft_memmove(buffer, buffer + 2, 8);
// 	// printf("Überlappung (dst < src): %s\n", buffer);
// 	return (0);
// }
