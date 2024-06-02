/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_grid.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: natferna <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/02 17:51:16 by natferna          #+#    #+#             */
/*   Updated: 2024/06/02 17:58:12 by natferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#define SIZE 4

void	ft_putchar(char c);
void	ft_number(int n);

void	print_grid(int grid[SIZE][SIZE])
{
	int	row;
	int	col;

	row = 0;
	while (row < SIZE)
	{
		col = 0;
		while (col < SIZE)
		{
			ft_number(grid[row][col]);
			if (col < SIZE - 1)
				ft_putchar(' ');
			col++;
		}
		ft_putchar('\n');
		row++;
	}
}
