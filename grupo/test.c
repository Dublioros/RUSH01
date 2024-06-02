/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: natferna <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/02 17:03:19 by natferna          #+#    #+#             */
/*   Updated: 2024/06/02 17:09:14 by natferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>

#define SIZE 4

void ft_putchar(char c)
{
    write(1, &c, 1);
}

void ft_putstr(char *str)
{
    while (*str)
        ft_putchar(*str++);
}

void ft_number(int n)
{
    if (n >= 10)
        ft_number(n / 10);
    ft_putchar(n % 10 + '0');
}

int is_in_row(int grid[SIZE][SIZE], int row, int value)
{
    int i = 0;
    while (i < SIZE)
    {
        if (grid[row][i] == value)
            return (1);
        i++;
    }
    return (0);
}

int is_in_col(int grid[SIZE][SIZE], int col, int value)
{
    int i = 0;
    while (i < SIZE)
    {
        if (grid[i][col] == value)
            return (1);
        i++;
    }
    return (0);
}

int check_row_left(int grid[SIZE][SIZE], int row, int expected)
{
    int max_seen = 0;
    int count = 0;
    int i = 0;

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

int check_row_right(int grid[SIZE][SIZE], int row, int expected)
{
    int max_seen = 0;
    int count = 0;
    int i = SIZE - 1;

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

int check_col_up(int grid[SIZE][SIZE], int col, int expected)
{
    int max_seen = 0;
    int count = 0;
    int i = 0;

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

int check_col_down(int grid[SIZE][SIZE], int col, int expected)
{
    int max_seen = 0;
    int count = 0;
    int i = SIZE - 1;

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

int solve(int grid[SIZE][SIZE], int row, int col, int *constr)
{
    if (row == SIZE)
        return (1);
    if (col == SIZE)
    {
        if (!check_row_left(grid, row, constr[8 + row]) || \
            !check_row_right(grid, row, constr[12 + row]))
            return (0);
        return solve(grid, row + 1, 0, constr);
    }
    int num = 1;
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

void print_grid(int grid[SIZE][SIZE])
{
    int row = 0;
    while (row < SIZE)
    {
        int col = 0;
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