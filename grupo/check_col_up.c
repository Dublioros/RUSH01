/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_col_up.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: natferna <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/02 18:24:41 by natferna          #+#    #+#             */
/*   Updated: 2024/06/02 18:26:44 by natferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#define SIZE 4

int	check_col_up(int grid[SIZE][SIZE], int col, int expected)
{
	int	max_seen;
	int	count;
	int	i;

	max_seen = 0;
	count = 0;
	i = 0;
	while (i < SIZE)
	{
		if (grid[i][col] > max_seen)
		{
			max_seen = grid[i][col];
			count++;
		}
		i++;
	}
	return (count == expected);
}
