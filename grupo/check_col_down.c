/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_col_down.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: natferna <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/02 18:27:17 by natferna          #+#    #+#             */
/*   Updated: 2024/06/02 18:30:54 by natferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#define SIZE 4

int	check_col_down(int grid[SIZE][SIZE], int col, int expected)
{
	int	max_seen;
	int	count;
	int	i;

	max_seen = 0;
	count = 0;
	i = SIZE - 1;
	while (i >= 0)
	{
		if (grid[i][col] > max_seen)
		{
			max_seen = grid[i][col];
			count++;
		}
		i--;
	}
	return (count == expected);
}
