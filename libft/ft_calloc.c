/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lunsold <lunsold@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/14 09:04:39 by lunsold           #+#    #+#             */
/*   Updated: 2025/10/22 12:25:40 by lunsold          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	char	*ptr;
	size_t	total_size;
	size_t	i;

	i = 0;
	total_size = count * size;
	ptr = malloc(total_size);
	if (!ptr)
		return (NULL);
	while (i < total_size)
	{
		((unsigned char *)ptr)[i] = 0;
		i++;
	}
	return (ptr);
}
// int	main(void)
// {
// 	size_t count;
// 	size_t size;
// 	void *result;
// 	size_t i;

// 	count = 5;
// 	size = sizeof(int);
// 	result = ft_calloc(count, size);
// 	if (result)
// 	{
// 		printf("Allocated memory initialized to zero:\n");
// 		for (i = 0; i < count; i++)
// 		{
// 			printf("%d ", ((int *)result)[i]);
// 		}
// 		printf("\n");
// 		free(result);
// 	}
// 	else
// 	{
// 		printf("Failed to allocate memory.\n");
// 	}
// 	return (0);
// }