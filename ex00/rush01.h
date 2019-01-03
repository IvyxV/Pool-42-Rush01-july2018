/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush01.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arrucins <arrucins@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/14 16:48:08 by arrucins          #+#    #+#             */
/*   Updated: 2018/07/14 18:14:34 by arrucins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RUSH01_H
# define RUSH01_H

# include <unistd.h>

int		ft_set(char **argv, int sudoku[9][9]);
void	ft_error(void);
void	ft_print(int sudoku[9][9]);
void	ft_solve(int sudoku[9][9], int row, int col);

#endif
