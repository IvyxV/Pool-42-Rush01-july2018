/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_solve.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arrucins <arrucins@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/14 00:09:57 by arrucins          #+#    #+#             */
/*   Updated: 2018/07/15 17:12:34 by arrucins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush01.h"

/*
** Return 1 if not duplicates, 0 if duplicates. Needs all 3 to be 1 to set.
*/

int		ft_row(int sudoku[9][9], int num, int col)
{
	int i;

	i = 0;
	while (i < 9)
	{
		if ('0' + (num % 10) == sudoku[i][col])
			return (0);
		i++;
	}
	return (1);
}

int		ft_column(int sudoku[9][9], int num, int row)
{
	int i;

	i = 0;
	while (i < 9)
	{
		if ('0' + (num % 10) == sudoku[row][i])
			return (0);
		i++;
	}
	return (1);
}

int		ft_grid(int sudoku[9][9], int num, int row, int col)
{
	int r;
	int c;

	row = (row / 3) * 3;
	col = (col / 3) * 3;
	r = 0;
	c = 0;
	while (r < 3)
	{
		while (c < 3)
		{
			if (sudoku[row + r][col + c] == '0' + (num % 10))
				return (0);
			c++;
		}
		r++;
	}
	return (1);
}

/*
** fills grid on X axis, then goes back to startt of new line, as in +Y.
*/

void	ft_switch(int sudoku[9][9], int row, int col)
{
	if (col < 8)
		ft_solve(sudoku, row, col + 1);
	else if (row <= 8)
		ft_solve(sudoku, row + 1, 0);
}

/*
** Backtrack, Bruteforce type. Tries NUM, checks 3 functions, if correct sets.
** Otherwise resets to 0, retries. If cell is filled calls ft_switch for next.
** Prints when all cells are filled.
*/

void	ft_solve(int sudoku[9][9], int row, int col)
{
	int num;

	num = 1;
	if (row > 8 && col > 7)
		ft_print(sudoku);
	if (sudoku[row][col] != '0')
		ft_switch(sudoku, row, col);
	else
	{
		while (num < 10)
		{
			if (ft_row(sudoku, num, col) == 1
					&& ft_column(sudoku, num, row) == 1
					&& ft_grid(sudoku, num, row, col) == 1)
			{
				sudoku[row][col] = '0' + (num % 10);
				ft_switch(sudoku, row, col);
			}
			num++;
		}
		sudoku[row][col] = '0';
	}
}
