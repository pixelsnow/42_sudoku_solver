/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgaynull <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/10 16:09:33 by rgaynull          #+#    #+#             */
/*   Updated: 2022/07/10 23:14:24 by vvagapov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

// Printing the grid row by row with newlines in between the rows and in the end
void	print(int **grid)
{
	int		row;
	int		col;
	char	c;

	row = 0;
	while (row < 9)
	{
		col = 0;
		while (col < 9)
		{
			c = grid[row][col] + '0';
			write(1, &c, 1);
			if (col < 8)
			{
				write(1, " ", 1);
			}
			col++;
		}
		write(1, "\n", 1);
		row++;
	}
}
