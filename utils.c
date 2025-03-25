/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moraouf <moraouf@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/23 17:23:15 by moraouf           #+#    #+#             */
/*   Updated: 2025/03/24 15:31:46 by moraouf          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"



size_t	count_word(const char *str, char set)
{
	size_t	i;
	size_t	count;

	i = 0;
	count = 0;
	while (str[i])
	{
		while (str[i] == set)
			i++;
		if (str[i])
			count++;
		while (str[i] && str[i] != set)
			i++;
	}
	return (count + 1);
}

size_t	lenght_word(const char *s, char set)
{
	size_t	lenght;

	lenght = 0;
	while (*s && *s != set)
	{
		s++;
		lenght++;
	}
	return (lenght);
}

void	free_memory(char **array, int elements)
{
	int	i;

	i = 0;
	while (i < elements)
	{
		free(array[i]);
		i++;
	}
	free(array);
}

char	**ft_split(char const *s, char c)
{
	char	**str_split;
	int		i;
	int		j;

	i = 0;
	str_split = malloc(sizeof(char *) * count_word(s, c));
	if (!str_split)
		return (NULL);
	while (*s)
	{
		if (*s != c)
		{
			j = 0;
			str_split[i] = malloc(lenght_word(s, c) + 1);
			if (!str_split[i])
				return (free_memory(str_split, i), NULL);
			while (*s && *s != c)
				str_split[i][j++] = *s++;
			str_split[i++][j] = '\0';
		}
		else
			s++;
	}
	return (str_split[i] = NULL, str_split);
}
