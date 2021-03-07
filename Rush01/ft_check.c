/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkang <mkang@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/06 19:08:35 by mkang             #+#    #+#             */
/*   Updated: 2021/03/06 19:29:55 by mkang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>

extern int	**g_board;
extern bool	**g_visited_row;
extern bool	**g_visited_column;

bool		ft_check_column_down(int column, int length)
{
	int	max_height;
	int	i;
	int	count;

	max_height = 0;
	count = 0;
	i = 1;
	while (i <= length)
	{
		if (g_board[i][column] > max_height)
		{
			count += 1;
			max_height = g_board[i][column];
		}
		i += 1;
	}
	return (g_board[0][column] == count);
}

bool		ft_check_column_up(int column, int length)
{
	int	max_height;
	int	i;
	int	count;

	max_height = 0;
	count = 0;
	i = length;
	while (i >= 1)
	{
		if (g_board[i][column] > max_height)
		{
			count += 1;
			max_height = g_board[i][column];
		}
		i -= 1;
	}
	return (g_board[length + 1][column] == count);
}

bool		ft_check_row_left(int row, int length)
{
	int	max_height;
	int	i;
	int	count;

	max_height = 0;
	count = 0;
	i = 1;
	while (i <= length)
	{
		if (g_board[row][i] > max_height)
		{
			count += 1;
			max_height = g_board[row][i];
		}
		i += 1;
	}
	return (g_board[row][0] == count);
}

bool		ft_check_row_right(int row, int length)
{
	int	max_height;
	int	i;
	int	count;

	max_height = 0;
	count = 0;
	i = length;
	while (i >= 1)
	{
		if (g_board[row][i] > max_height)
		{
			count += 1;
			max_height = g_board[row][i];
		}
		i -= 1;
	}
	return (g_board[row][length + 1] == count);
}

bool		ft_check_column_all(int length)
{
	bool	possible;
	int		i;

	possible = true;
	i = 1;
	while (i <= length)
	{
		if (!(ft_check_column_down(i, length) && ft_check_column_up(i, length)))
		{
			possible = false;
			break ;
		}
		i += 1;
	}
	return (possible);
}
