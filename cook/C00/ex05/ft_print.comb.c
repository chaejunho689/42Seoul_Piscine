/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print.comb.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchae <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/22 19:25:29 by jchae             #+#    #+#             */
/*   Updated: 2021/03/06 20:22:58 by desire           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_print_comb(void)
{
	int a;
	int b;
	int c;

	a = 0 - 1;
	while (++a <= 7)
	{
		b = a;
		while (++b <= 8)
		{
			c = b;
			while (++c <= 9)
			{
				ft_putchar('0' + a);
				ft_putchar('0' + b);
				ft_putchar('0' + c);
				if (a != 7)
				{
					ft_putchar(',');
					ft_putchar(' ');
				}
			}
		}
	}
}

int	main(void)
{
	ft_print_comb();
	return 0;
}
