/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lunsold <lunsold@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/13 18:53:46 by lunsold           #+#    #+#             */
/*   Updated: 2025/10/15 17:13:11 by lunsold          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	j;

	if (*needle == '\0')
		return ((char *)haystack);
	i = 0;
	while (haystack[i] != '\0' && i < len)
	{
		j = 0;
		while (needle[j] != '\0' && i + j < len && haystack[i + j] == needle[j])
			j++;
		if (needle[j] == '\0')
			return ((char *)haystack + i);
		i++;
	}
	return (NULL);
}
// int	main(void)
// {
// 	const char	*haystack = "Hello, World!";
// 	const char	*needle = "World";
// 	size_t		len;
// 	char		*result;

// 	len = 13;
// 	result = ft_strnstr(haystack, needle, len);
// 	if (result)
// 	{
// 		printf("Found substring: %s\n", result);
// 	}
// 	else
// 	{
// 		printf("Substring not found within the specified length.\n");
// 	}
// 	return (0);
// }
