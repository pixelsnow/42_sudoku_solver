/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sudoku.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvagapov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/09 13:43:16 by vvagapov          #+#    #+#             */
/*   Updated: 2022/07/10 23:18:16 by vvagapov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>

int		is_suitable(int **grid, int row, int col, int num);
void	fill(int **grid, char **argv);
void	print(int **grid);
void	allocate_memory(int ***grid);
void	print_error(void);
void	free_memory(int **grid);

// Goes through all possible solutions and counts them,
// putting the number of solutions into solution_counter using a pointer.
// The "++(*solution_counter)" part of the condition is pointless
// and only serves to cut down on the number of lines :P
// This part of the condition is always true,
// but it iterates solution_counter, which is what I need. 
void	count_solutions(int **grid, int *solution_counter)
{
	int	i;
	int	num;

	i = 0;
	while (i < 81 && grid [i / 9][i % 9] != 0)
		i++;
	if (i == 81 && ++(*solution_counter))
		return ;
	else
	{
		num = 1;
		while (num <= 9)
		{
			if (is_suitable(grid, i / 9, i % 9, num))
			{
				grid[i / 9][i % 9] = num;
				count_solutions(grid, solution_counter);
				grid[i / 9][i % 9] = 0;
			}
			num++;
		}
	}
	return ;
}

// Solves the grid and stops at the first solution.
// The recursion stops if we have reached the bottom right corner
// of the grid and the last element is not 0,
// meaning the whole grid is filled with fitting numbers.
// If the solution is not found in the current recursion branch,
// the element in question is set back to zero and 0 is returned.
int	solve(int **grid)
{
	int	i;
	int	num;

	i = 0;
	while (i < 81 && grid [i / 9][i % 9] != 0)
		i++;
	if (i == 81)
		return (1);
	else
	{
		num = 1;
		while (num <= 9)
		{
			if (is_suitable(grid, i / 9, i % 9, num))
			{
				grid[i / 9][i % 9] = num;
				if (solve(grid))
					return (1);
				grid[i / 9][i % 9] = 0;
			}
			num++;
		}
	}
	return (0);
}

// If the number of arguments is 9, this main function creates a grid,
// fills it with numbers from the input, counts solutions and prints
// a solution is the sudoku is valid. Otherwise it prints an error message. 
int	main(int argc, char **argv)
{
	int	**grid;
	int	solution_counter;

	if (argc == 10)
	{
		allocate_memory(&grid);
		fill(grid, argv);
		solution_counter = 0;
		count_solutions(grid, &solution_counter);
		if (solution_counter == 1)
		{
			solve(grid);
			print(grid);
		}
		else
			print_error();
		free_memory(grid);
	}
	else
		print_error();
	return (0);
}
