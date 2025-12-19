/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lunsold <lunsold@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/20 17:43:40 by lunsold           #+#    #+#             */
/*   Updated: 2025/10/20 17:45:46 by lunsold          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*str;
	int		i;
	int		length;

	i = 0;
	length = ft_strlen(s);
	str = (char *)malloc(sizeof(char) * (length + 1));
	if (str == NULL)
		return (NULL);
	while (s[i] != '\0')
	{
		str[i] = f(i, s[i]);
		i++;
	}
	str[length] = '\0';
	return (str);
}
// int	main(void)
// {
// 	const char	*s = "Hello, World!";
// 	char		*result;
// 	int			i;

// 	char my_func(unsigned int index, char c)
// 	{
// 		if (c >= 'a' && c <= 'z')
// 			return (c - 32);
// 		else if (c >= 'A' && c <= 'Z')
// 			return (c + 32);
// 		return (c);
// 	}
// 	result = ft_strmapi(s, my_func);
// 	if (result)
// 	{
// 		printf("Original string: %s\n", s);
// 		printf("Mapped string: %s\n", result);
// 		free(result);
// 	}
// 	else
// 	{
// 		printf("Failed to allocate memory for mapped string.\n");
// 	}
// 	return (0);
// }
