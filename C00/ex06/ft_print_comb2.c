/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchae <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/22 19:23:50 by jchae             #+#    #+#             */
/*   Updated: 2021/03/06 20:43:03 by jchae            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_display(int a, int b)
{
	char one;
	char two;
	char three;
	char four;

	ft_putchar(one = '0' + a / 10);
	ft_putchar(two = '0' + a % 10);
	ft_putchar(' ');
	ft_putchar(three = '0' + b / 10);
	ft_putchar(four = '0' + b % 10);
	if (!(a == 98 && b == 99))
	{
		ft_putchar(',');
		ft_putchar(' ');
	}
}

void	ft_print_comb2(void)
{
	int a;
	int b;

	a = 0;
	while (a <= 98)
	{
		b = a + 1;
		while (b <= 99)
		{
			ft_display(a, b);
			b++;
		}
		a++;
	}
}

int		main()
{
	ft_print_comb2();
	return 0;
}
