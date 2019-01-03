/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlicausi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/15 16:24:55 by tlicausi          #+#    #+#             */
/*   Updated: 2018/07/15 21:20:13 by arrucins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush01.h"

void	ft_error(void)
{
	write(1, "Error\n", 6);
}

int		main(int argc, char **argv)
{
	int sudoku[9][9];

	if (argc == 10)
	{
		if (ft_set(argv, sudoku) == 1)
			ft_solve(sudoku, 0, 0);
		else
			ft_error();
	}
	else
		ft_error();
	return (0);
}
