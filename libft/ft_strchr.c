/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lunsold <lunsold@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/09 12:12:36 by lunsold           #+#    #+#             */
/*   Updated: 2025/10/16 18:07:25 by lunsold          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	int	i;

	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] == (char)c)
			return ((char *)&s[i]);
		i++;
	}
	if (s[i] == (char)c)
		return ((char *)&s[i]);
	return (NULL);
}
// int	main(void)
// {
// 	const char	*s = "Hello, World!";
// 	int			c;
// 	char		*result;

// 	c = 'W';
// 	result = ft_strchr(s, c);
// 	if (result)
// 	{
// 		printf("Character '%c' found at position: %ld\n", c, result - s);
// 	}
// 	else
// 	{
// 		printf("Character '%c' not found in the string.\n", c);
// 	}
// 	return (0);
// }
