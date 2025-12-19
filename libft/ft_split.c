/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lunsold <lunsold@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/16 17:20:02 by lunsold           #+#    #+#             */
/*   Updated: 2025/10/21 16:22:59 by lunsold          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_count_words(char const *s, char c)
{
	int	word_counter;
	int	letter_counter;
	int	in_word;

	word_counter = 0;
	letter_counter = 0;
	in_word = 0;
	while (s[letter_counter] != '\0')
	{
		if (s[letter_counter] == c)
			in_word = 0;
		else if (!in_word)
		{
			in_word = 1;
			word_counter++;
		}
		letter_counter++;
	}
	return (word_counter);
}

static char	**free_string(char **split, int index)
{
	while (index > 0)
		free(split[--index]);
	free(split);
	return (NULL);
}

static char	**create_substr(char **split, char const *s, char c, int index)
{
	int	start;
	int	length;
	int	counter;

	counter = 0;
	while (s[counter] != '\0')
	{
		while (s[counter] == c && s[counter] != '\0')
			counter++;
		start = counter;
		length = 0;
		while (s[counter] != c && s[counter] != '\0')
		{
			counter++;
			length++;
		}
		if (length > 0)
		{
			split[index] = ft_substr(s, start, length);
			if (split[index] == NULL)
				return (free_string(split, index), NULL);
			index++;
		}
	}
	return (split[index] = NULL, split);
}

char	**ft_split(char const *s, char c)
{
	char	**split;
	int		word_counter;
	int		index;

	index = 0;
	if (!s)
		return (NULL);
	word_counter = ft_count_words((char *)s, c);
	split = (char **)malloc(sizeof(char *) * (word_counter + 1));
	if (split == NULL)
		return (NULL);
	split = create_substr(split, s, c, index);
	if (split == NULL)
		return (NULL);
	return (split);
}
// int	main(void)
// {
// 	char	**result;
// 	char	*str;
// 	char	delimiter;
// 	int		i;

// 	str = ",,,,,,,,Hello,,World,,This,is,,,,,,a,test,,,,,";
// 	delimiter = ',';
// 	result = ft_split(str, delimiter);
// 	if (result)
// 	{
// 		i = 0;
// 		while (result[i] != NULL)
// 		{
// 			printf("Substring %d: %s\n", i, result[i]);
// 			free(result[i]);
// 			i++;
// 		}
// 		free(result);
// 	}
// 	else
// 	{
// 		printf("Memory allocation failed\n");
// 	}
// 	return (0);
// }
