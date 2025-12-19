/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lunsold <lunsold@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/08 20:43:53 by lunsold           #+#    #+#             */
/*   Updated: 2025/10/20 15:03:05 by lunsold          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t			i;
	unsigned char	*s;
	unsigned char	*d;

	i = 0;
	if (dst == src)
		return (NULL);
	d = ((unsigned char *)dst);
	s = ((unsigned char *)src);
	while (i < n)
	{
		d[i] = s[i];
		i++;
	}
	return (d);
}
