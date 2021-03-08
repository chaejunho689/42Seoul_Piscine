/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkang <mkang@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/06 19:01:10 by mkang             #+#    #+#             */
/*   Updated: 2021/03/06 19:19:37 by mkang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>
#include <stdlib.h>

extern int	**g_board;
extern bool	**g_visited_row;
extern bool	**g_visited_column;

void		ft_init_board(int length)
{
	int	i;
	int	j;

	g_board = (int **)malloc(sizeof(int *) * (length + 2));
	i = 0;
	while (i < length + 2)
	{
		g_board[i] = (int *)malloc(sizeof(int) * (length + 2));
		j = 0;
		while (j < length + 2)
		{
			g_board[i][j] = 0;
			j += 1;
		}
		i += 1;
	}
}

void		ft_init_visited(int length)
{
	int	i;
	int	j;

	g_visited_row = (bool **)malloc(sizeof(bool *) * (length + 2));
	g_visited_column = (bool **)malloc(sizeof(bool *) * (length + 2));
	i = 0;
	while (i < length + 2)
	{
		g_visited_row[i] = (bool *)malloc(sizeof(bool) * (length + 2));
		g_visited_column[i] = (bool *)malloc(sizeof(bool) * (length + 2));
		j = 0;
		while (j < length + 2)
		{
			g_visited_row[i][j] = false;
			g_visited_column[i][j] = false;
			j += 1;
		}
		i += 1;
	}
}

void		ft_init(int length)
{
	ft_init_board(length);
	ft_init_visited(length);
}
