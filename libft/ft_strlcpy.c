/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lunsold <lunsold@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/08 21:29:20 by lunsold           #+#    #+#             */
/*   Updated: 2025/10/20 14:42:39 by lunsold          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	i;

	i = 0;
	if (dstsize == 0)
		return (ft_strlen(src));
	while (src[i] != '\0' && i < dstsize - 1)
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (ft_strlen(src));
}
// int	main(void)
// {
// 	char		dst[20];
// 	const char	*src;
// 	size_t		dstsize;
// 	size_t		result;

// 	src = "Hello, World!";
// 	dstsize = 7;
// 	result = ft_strlcpy(dst, src, dstsize);
// 	printf("Copied string: %s\n", dst);
// 	printf("Total length: %zu\n", result);
// 	return (0);
// }
