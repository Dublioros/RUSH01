/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_in_col.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: natferna <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/02 18:16:10 by natferna          #+#    #+#             */
/*   Updated: 2024/06/02 18:18:54 by natferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#define SIZE 4

int	is_in_col(int grid[SIZE][SIZE], int col, int value)
{
	int	i;

	i = 0;
	while (i < SIZE)
	{
		if (grid[i][col] == value)
			return (1);
		i++;
	}
	return (0);
}
