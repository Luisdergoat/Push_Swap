/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lunsold <lunsold@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/16 12:09:38 by lunsold           #+#    #+#             */
/*   Updated: 2025/10/21 15:46:25 by lunsold          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		i;
	int		j;
	char	*str;

	i = 0;
	j = 0;
	str = malloc((ft_strlen(s1) + ft_strlen(s2) + 1) * sizeof(char));
	if (!str)
		return (NULL);
	while (s1[j] != '\0')
	{
		str[i] = s1[j];
		j++;
		i++;
	}
	j = 0;
	while (s2[j] != '\0')
	{
		str[i] = s2[j];
		j++;
		i++;
	}
	str[i] = '\0';
	return (str);
}
// int	main(void)
// {
// 	const char	*s1 = "Hello, ";
// 	const char	*s2 = "world!";
// 	char		*result;

// 	result = ft_strjoin(s1, s2);
// 	if (result)
// 	{
// 		printf("Joined string: %s\n", result);
// 		free(result);
// 	}
// 	else
// 	{
// 		printf("Failed to allocate memory for joined string.\n");
// 	}
// 	return (0);
// }
