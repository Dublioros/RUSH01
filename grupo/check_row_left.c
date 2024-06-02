/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_row_left.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: natferna <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/02 18:19:18 by natferna          #+#    #+#             */
/*   Updated: 2024/06/02 18:21:27 by natferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#define SIZE 4

int	check_row_left(int grid[SIZE][SIZE], int row, int expected)
{
	int	max_seen;
	int	count;
	int	i;

	max_seen = 0;
	count = 0;
	i = 0;
	while (i < SIZE)
	{
		if (grid[row][i] > max_seen)
		{
			max_seen = grid[row][i];
			count++;
		}
		i++;
	}
	return (count == expected);
}
