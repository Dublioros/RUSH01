/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: natferna <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/02 18:31:09 by natferna          #+#    #+#             */
/*   Updated: 2024/06/02 18:37:51 by natferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#define SIZE 4

int	solve(int grid[SIZE][SIZE], int row, int col, int *constr)
{
	int	num;

	num = 1;
	if (row == SIZE)
		return (1);
	if (col == SIZE)
	{
		if (!check_row_left(grid, row, constr[8 + row]) || \
			!check_row_right(grid, row, constr[12 + row]))
			return (0);
		return (solve(grid, row + 1, 0, constr));
	}
	while (num <= SIZE)
	{
		if (!is_in_row(grid, row, num) && !is_in_col(grid, col, num))
		{
			grid[row][col] = num;
			if (solve(grid, row, col + 1, constr))
				return (1);
			grid[row][col] = 0;
		}
		num++;
	}
	return (0);
}
