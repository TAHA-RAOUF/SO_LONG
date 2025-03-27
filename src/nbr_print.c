/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nbr_print.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moraouf <moraouf@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/27 14:11:00 by moraouf           #+#    #+#             */
/*   Updated: 2025/03/27 18:02:15 by moraouf          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_putnbr(int nb)
{
	if (nb > 9)
	{
		ft_putnbr(nb / 10);
		ft_putnbr(nb % 10);
	}
	else
		ft_putchar(nb + 48);
}

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	print_moves(void)
{
	static int	count;

	count++;
	write(1, "Move :", 7);
	ft_putnbr(count);
	write(1, "\n", 1);
}

int	count_characters(t_list *list, char c)
{
	int	i;
	int	j;
	int	count;

	i = 0;
	j = 0;
	count = 0;
	while (list->map[i])
	{
		j = 0;
		while (list->map[i][j])
		{
			if (list->map[i][j] == c)
				count++;
			j++;
		}
		i++;
	}
	return (count);
}

void	winner(void)
{
	print_moves();
	write(1, "You are a winner", 16);
}
