/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush02.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkoh <jkoh@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/20 22:32:01 by jkoh              #+#    #+#             */
/*   Updated: 2021/02/20 22:39:11 by jkoh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putchar(char c);

void	rush(int a, int b)
{
	int row;
	int len;

	row = a;
	len = b;
	while (b && (len >= 0 && row >= 0))
	{
		while (a)
		{
			if ((b == len && a == row) || (b == len && a == 1))
				ft_putchar('A');
			else if ((row > 1 && len > 1) && (a + b == 2))
				ft_putchar('C');
			else if (b == 1 && a == row)
				ft_putchar('C');
			else if ((b != len && b != 1) && (a != row && a != 1))
				ft_putchar(' ');
			else
				ft_putchar('B');
			a--;
		}
		ft_putchar('\n');
		a = row;
		b--;
	}
}
