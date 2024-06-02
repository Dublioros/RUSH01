/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_row_right.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: natferna <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/02 18:22:03 by natferna          #+#    #+#             */
/*   Updated: 2024/06/02 18:24:03 by natferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#define SIZE 4

int	check_row_right(int grid[SIZE][SIZE], int row, int expected)
{
	int	max_seen;
	int	count;
	int	i;

	max_senn = 0;
	count = 0;
	I = SIZE - 1;
	while (i >= 0)
	{
		if (grid[row][i] > max_seen)
		{
			max_seen = grid[row][i];
			count++;
		}
		i--;
	}
	return (count == expected);
}
