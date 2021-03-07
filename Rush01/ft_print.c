/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkang <mkang@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/06 19:14:31 by mkang             #+#    #+#             */
/*   Updated: 2021/03/07 16:49:50 by desire           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c);
void 	ft_putstr(char *str);
extern int	**g_board;

void		ft_print_error()
{
	ft_putstr("error");
	ft_putchar('\n');
}

void		ft_print_board(int length)
{
	int	i;
	int	j;

	i = 0;
	while (i < length + 2)
	{
		j = 0;
		while (j < length + 2)
		{
			ft_putchar('0' + g_board[i][j];
			j += 1;
		}
		ft_putchar('\n');
		i += 1;
	}
}
