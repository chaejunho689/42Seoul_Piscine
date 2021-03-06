#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>


void 	ft_putstr(); //추가함

int		**g_board;
bool	g_possbile;
bool	g_visited_row[20][20];
bool	g_visited_column[20][20];

char	**ft_split(char *str);
int		ft_count_words(char *str);
void	ft_print_error()
{
	printf("error\n");
}
bool	ft_is_invalid(char **str, int length);


// 추가함
void	ft_putstr(char *str)
{
	int i;

	while(str[i] != '\0')
	{
			write(1, &str[i++], 1);
			i++;
	}
}

void	ft_putchar(char c)
{
	write(1, &c, 1);
}


void	ft_print_board(int length)
{
	int	i;
	int	j;

	i = 0;
	while (i < length + 2)
	{
		j = 0;
		while (j < length + 2)
		{
			ft_putchar('0' + g_board[i][j]); // 추가함
			if (j != (length)) // 추가함
			{
				ft_putchar(' ');
			}
//			printf("%d ", g_board[i][j]);
			j += 1;
		}
		ft_putchar('\n');
//		printf("\n");
		i += 1;
	}
}

void	ft_init_board(int length)
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

bool	ft_check_row_left(int row, int length)
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

bool	ft_check_row_right(int row, int length)
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

bool	ft_check_column_down(int column, int length)
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

bool	ft_check_column_up(int column, int length)
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

void	ft_fill_blank(int length, int row, int column)
{
	int		i;
	int		j;
	bool	flag;

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
		flag = true;
		j = 1;
		while (j <= column)
		{
			if (!ft_check_column_down(j, length) ||
					!ft_check_column_up(j, length))
			{
				flag = false;
				break;
			}
			j += 1;
		}
		if (flag)
		{
			ft_print_board(length);
			printf("-----------------\n");
			g_possbile = true;
		}
		return ;
	}
	i = 1;
	while (i <= length)
	{
		if (g_visited_row[row][i] == false && g_visited_column[column][i] == false)
		{
			g_visited_row[row][i] = true;
			g_visited_column[column][i] = true;
			g_board[row][column] = i;
			ft_fill_blank(length, row, column + 1);
			g_visited_row[row][i] = false;
			g_visited_column[column][i] = false;
			g_board[row][column] = 0;
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
	ft_init_board(length);
	ft_fill_visible_boxes(visible_boxes, length);
	ft_fill_blank(length, 1, 1);

	if (g_possbile == false)
		ft_print_error();
}
