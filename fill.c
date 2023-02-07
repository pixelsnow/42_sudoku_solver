/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgaynull <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/10 16:05:13 by rgaynull          #+#    #+#             */
/*   Updated: 2022/07/10 23:14:03 by vvagapov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// Going through the array of arguments and the grid array simultaneously 
// using i and j indexes and filling the grid with values from the 
// input strings converted to integers

void	fill(int **grid, char **argv)
{
	int	i;
	int	j;

	i = 0;
	while (i < 9)
	{
		j = 0;
		while (j < 9)
		{
			if ((argv[i + 1][j] >= '1') && (argv[i + 1][j] <= '9'))
				grid[i][j] = (argv[i + 1][j] - '0');
			else
				if (argv[i + 1][j] == '.')
					grid[i][j] = 0;
			j++;
		}
		i++;
	}
}
