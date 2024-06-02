/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_in_row.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: natferna <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/02 18:14:13 by natferna          #+#    #+#             */
/*   Updated: 2024/06/02 18:15:36 by natferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#define SIZE 4

int	is_in_row(int grid[SIZE][SIZE], int row, int value)
{
	int	i;

	i = 0;
	while (i < SIZE)
	{
		if (grid[row][i] == value)
			return (1);
		i++;
	}
	return (0);
}
