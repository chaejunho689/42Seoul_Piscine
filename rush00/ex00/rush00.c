/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Rush00.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkoh <jkoh@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/20 10:34:05 by jkoh              #+#    #+#             */
/*   Updated: 2021/02/20 22:58:12 by jkoh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c);

void	rush(int a, int b)
{
	int row;
	int len;

	row = a;
	len = b;
	while (b)
	{
		if (len <= 0 || row <= 0)
			break ;
		while (a)
		{
			if ((b == len || b == 1) && (a == row || a == 1))
				ft_putchar('o');
			else if (b == len || b == 1)
				ft_putchar('-');
			else if ((b != len && b != 1) && (a == row || a == 1))
				ft_putchar('|');
			else
				ft_putchar(' ');
			a--;
		}
		ft_putchar('\n');
		a = row;
		b--;
	}
}
