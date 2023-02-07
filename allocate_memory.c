/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   allocate_memory.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgaynull <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/10 16:14:41 by rgaynull          #+#    #+#             */
/*   Updated: 2022/07/10 16:39:51 by rgaynull         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

// Allocating memory for 9 rows and 9 columns
void	allocate_memory(int ***grid)
{
	int	i;

	i = 0;
	*grid = (int **)malloc(sizeof(int *) * 9);
	while (i < 9)
	{
		(*grid)[i] = (int *)malloc(sizeof(int) * 9);
		i++;
	}
}
