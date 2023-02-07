/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_suitable.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgaynull <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/10 15:45:53 by rgaynull          #+#    #+#             */
/*   Updated: 2022/07/10 23:13:28 by vvagapov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	match_row(int **grid, int row, int num)
{
	int	k;

	k = 0;
	while (k < 9)
	{
		if (grid[row][k] == num)
			return (0);
		k++;
	}
	return (1);
}

int	match_column(int **grid, int col, int num)
{
	int	k;

	k = 0;
	while (k < 9)
	{
		if (grid[k][col] == num)
			return (0);
		k++;
	}
	return (1);
}

int	match_square(int **grid, int i, int j, int num)
{
	int	a;
	int	b;

	a = i / 3 * 3;
	while (a < (i / 3 + 1) * 3)
	{
		b = j / 3 * 3;
		while (b < (j / 3 + 1) * 3)
		{
			if (grid[a][b] == num)
				return (0);
			b++;
		}
		a++;
	}
	return (1);
}

// Returns 1 if number num doesn't conflict with numbers 
// in given column, row and block.
// Returns 0 if a conflict is found.
int	is_suitable(int **grid, int row, int col, int num)
{
	if (match_square(grid, row, col, num)
		&& match_row(grid, row, num)
		&& match_column(grid, col, num))
		return (1);
	else
		return (0);
}
