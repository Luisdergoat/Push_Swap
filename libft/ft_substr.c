/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lunsold <lunsold@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/14 09:25:57 by lunsold           #+#    #+#             */
/*   Updated: 2025/10/21 16:15:49 by lunsold          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*sub_str;
	size_t	i;
	size_t	s_len;

	i = 0;
	if (s == NULL)
		return (NULL);
	s_len = ft_strlen(s);
	if (start >= s_len)
	{
		sub_str = (char *)malloc(sizeof(char) * (1));
		if (!sub_str)
			return (NULL);
		*sub_str = '\0';
		return (sub_str);
	}
	if (len > s_len - start)
		len = s_len - start;
	sub_str = (char *)malloc(sizeof(char) * (len + 1));
	if (!sub_str)
		return (NULL);
	while (s[i] != '\0' && i < len)
		sub_str[i++] = s[start++];
	sub_str[i] = '\0';
	return (sub_str);
}

// int	main(void)
// {
// 	unsigned int	start;
// 	size_t			len;
// 	char			*result;
// 	const char		*str = "Hello, World!";

// 	start = 7;
// 	len = 5;
// 	result = ft_substr(str, start, len);
// 	if (result)
// 	{
// 		printf("Substring: %s\n", result);
// 		free(result);
// 	}
// 	else
// 	{
// 		printf("Failed to allocate memory for substring.\n");
// 	}
// 	return (0);
// }
