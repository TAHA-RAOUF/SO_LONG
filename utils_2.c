/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moraouf <moraouf@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/25 00:54:53 by moraouf           #+#    #+#             */
/*   Updated: 2025/03/25 02:52:39 by moraouf          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */




#include "so_long.h"




void	free_mem(char **array)
{
	int	i;

	i = 0;
	while (array[i])
	{
		free(array[i]);
		i++;
	}
	free(array);
}