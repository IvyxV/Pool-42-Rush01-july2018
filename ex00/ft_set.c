/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_set.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arrucins <arrucins@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/14 00:09:57 by arrucins          #+#    #+#             */
/*   Updated: 2018/07/15 17:04:33 by arrucins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush01.h"

/*
** Iterates specific row for known number. Returns number count
** If > 1 this is an entry error
*/

int		ft_row_check(int sudoku[9][9], int num, int col)
{
	int i;
	int mark;

	i = 0;
	mark = 0;
	while (i < 9)
	{
		if (num == sudoku[i][col])
			mark++;
		i++;
	}
	return (mark);
}

/*
** Iterates specific col for known number. Returns number count
** If > 1 this is an entry error
*/

int		ft_column_check(int sudoku[9][9], int num, int row)
{
	int i;
	int mark;

	i = 0;
	mark = 0;
	while (i < 9)
	{
		if (num == sudoku[row][i])
			mark++;
		i++;
	}
	return (mark);
}

/*
** Iterates specific square for known number. Returns number count.
** Row and col is a square delimiter. Abuses Division result to lock upon valid
** sudoku square.
** If > 1 this is an entry error
*/

int		ft_grid_check(int sudoku[9][9], int num, int row, int col)
{
	int r;
	int c;
	int mark;

	mark = 0;
	row = (row / 3) * 3;
	col = (col / 3) * 3;
	r = 0;
	c = 0;
	while (r < 3)
	{
		while (c < 3)
		{
			if (sudoku[row + r][col + c] == num)
				mark++;
			c++;
		}
		r++;
	}
	return (mark);
}

/*
** Uses same checkers as in Backtrack. Watch for dupe numbers, and non-numbers
*/

int		ft_check_entry(int sudoku[9][9])
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (i < 9)
	{
		j = 0;
		while (j < 9)
		{
			if (sudoku[i][j] < '0' || sudoku[i][j] > '9')
				return (0);
			if (sudoku[i][j] != '0')
			{
				if (ft_row_check(sudoku, sudoku[i][j], j) > 1
						|| ft_column_check(sudoku, sudoku[i][j], i) > 1
						|| ft_grid_check(sudoku, sudoku[i][j], i, j) > 1)
					return (0);
			}
			j++;
		}
		i++;
	}
	return (1);
}

/*
** Checks for valid numbers in argv, and for valid numbers as of above
*/

int		ft_set(char **argv, int sudoku[9][9])
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (i <= 8)
	{
		while (j <= 8)
		{
			if (argv[i + 1][j] == '.')
				sudoku[i][j] = '0';
			else
				sudoku[i][j] = argv[i + 1][j];
			j++;
		}
		if (argv[i + 1][j])
			return (0);
		j = 0;
		i++;
	}
	if (ft_check_entry(sudoku) == 0)
		return (0);
	return (1);
}
