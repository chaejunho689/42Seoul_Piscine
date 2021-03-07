/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkang <mkang@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/06 18:27:34 by mkang             #+#    #+#             */
/*   Updated: 2021/03/06 22:45:51 by mkang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>
#include <stdlib.h>

int		**g_board;
bool	**g_visited_row;
bool	**g_visited_column;
bool	g_possbile;

char	**ft_split(char *str);
void	ft_init(int length);
bool	ft_check_column_all(int length);
bool	ft_check_row_left(int row, int length);
bool	ft_check_row_right(int row, int length);
bool	ft_is_invalid(char **str, int length);
int		ft_count_words(char *str);
void	ft_print_error();
void	ft_print_board(int length);

void	ft_visit(int row, int column, bool visit, int nbr)
{
	g_visited_row[row][i] = visit;
	g_visited_column[column][i] = visit;
	g_board[row][column] = nbr;
}

void	ft_fill_visible_boxes(char **visible_boxes, int length)
{
	int	i;

	i = 0;
	while (i < length)
	{
		g_board[0][i + 1] = *visible_boxes[i] - '0';
		g_board[length + 1][i + 1] = *visible_boxes[length + i] - '0';
		g_board[i + 1][0] = *visible_boxes[length * 2 + i] - '0';
		g_board[i + 1][length + 1] = *visible_boxes[length * 3 + i] - '0';
		i += 1;
	}
}

void	ft_fill_blank(int length, int row, int column)
{
	int	i;

	if (g_possbile)
		return ;
	if (column == length + 1)
	{
		if (ft_check_row_left(row, length) && ft_check_row_right(row, length))
			ft_fill_blank(length, row + 1, 1);
		return ;
	}
	if (row == length + 1)
	{
		if (ft_check_column_all(length))
		{
			ft_print_board(length);
			g_possbile = true;
		}
		return ;
	}
	i = 1;
	while (i <= length)
	{
		if (g_visited_row[row][i] == false &&
				g_visited_column[column][i] == false)
		{
			ft_visit(row, column, true, i);
			ft_fill_blank(length, row, column + 1);
			ft_visit(row, column, false, 0);
		}
		i += 1;
	}
}

void	rush(char *str)
{
	char	**visible_boxes;
	int		length;

	visible_boxes = ft_split(str);
	length = ft_count_words(str) / 4;
	if (ft_count_words(str) % 4 != 0 || ft_is_invalid(visible_boxes, length))
	{
		ft_print_error();
		return ;
	}
	ft_init(length);
	ft_fill_visible_boxes(visible_boxes, length);
	ft_fill_blank(length, 1, 1);
	if (g_possbile == false)
		ft_print_error();
}
