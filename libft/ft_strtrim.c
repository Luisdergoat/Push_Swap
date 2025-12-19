/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lunsold <lunsold@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/16 16:58:22 by lunsold           #+#    #+#             */
/*   Updated: 2025/10/20 13:44:14 by lunsold          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	length;
	size_t	i;

	if (!s1)
		return (NULL);
	length = ft_strlen(s1);
	i = 0;
	while (s1[i] != '\0' && ft_strrchr(set, s1[i]) != NULL)
		i++;
	while (length > i && ft_strrchr(set, s1[length - 1]) != NULL)
		length--;
	return (ft_substr(s1, i, length - i));
}
// int	main(void)
// {
// 	const char	*s1 = "Hello, World!";
// 	const char	*set = " World!";
// 	char		*result;

// 	result = ft_strtrim(s1, set);
// 	if (result)
// 	{
// 		printf("Trimmed string: %s\n", result);
// 		free(result);
// 	}
// 	else
// 	{
// 		printf("Failed to allocate memory for trimmed string.\n");
// 	}
// 	return (0);
// }
