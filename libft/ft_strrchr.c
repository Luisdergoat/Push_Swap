/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lunsold <lunsold@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/13 11:04:30 by lunsold           #+#    #+#             */
/*   Updated: 2025/10/13 12:19:11 by lunsold          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int		i;
	char	*temp;

	i = 0;
	while (s[i])
		i++;
	while (i >= 0)
	{
		if (s[i] == (char)c)
		{
			temp = (char *)&s[i];
			return (temp);
		}
		i--;
	}
	return (NULL);
}
// int	main(void)
// {
// 	char	*c;

// 	c = ft_strrchr("Hello world", 'H');
// 	printf("Res: %s\n", c);
// }
