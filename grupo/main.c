/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: natferna <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/02 17:58:36 by natferna          #+#    #+#             */
/*   Updated: 2024/06/02 18:13:06 by natferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#define SIZE 4

void	print_grid(int grid[SIZE][SIZE]);
void ft_putchar(char c);
void ft_putstr(char *str);
void ft_number(int n);
int is_in_row(int grid[SIZE][SIZE], int row, int value);
int is_in_col(int grid[SIZE][SIZE], int col, int value);
int check_row_left(int grid[SIZE][SIZE], int row, int expected);
int check_row_right(int grid[SIZE][SIZE], int row, int expected);
int check_col_up(int grid[SIZE][SIZE], int col, int expected);
int check_col_down(int grid[SIZE][SIZE], int col, int expected);
int solve(int grid[SIZE][SIZE], int row, int col, int *constr);


int main(int argc, char **argv)
{
    if (argc != 2)
    {
        ft_putstr("Error\n");
        return (1);
    }
    
    int *constr = (int *)malloc(sizeof(int) * 16);
    if (!constr)
    {
        ft_putstr("Error\n");
        return (1);
    }

    int i = 0;
    while (i < 16)
    {
        constr[i] = argv[1][i * 2] - '0';
        i++;
    }

    int grid[SIZE][SIZE] = {0};

    if (solve(grid, 0, 0, constr))
        print_grid(grid);
    else
        ft_putstr("Error\n");

    free(constr);
    return (0);
}