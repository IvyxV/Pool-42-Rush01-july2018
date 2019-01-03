/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arrucins <arrucins@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/14 00:09:57 by arrucins          #+#    #+#             */
/*   Updated: 2018/07/15 14:11:08 by arrucins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush01.h"

/*
** Prints as soon ft_solve finds a solution
** (j != 8 ) as we don't want extra whitespace at end of line.
*/

void		ft_print(int sudoku[9][9])
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (i <= 8)
	{
		while (j <= 8)
		{
			write(1, &sudoku[i][j], 1);
			if (j != 8)
				write(1, " ", 1);
			j++;
		}
		j = 0;
		write(1, "\n", 1);
		i++;
	}
}
