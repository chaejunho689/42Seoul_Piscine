/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchae <jchae@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/24 23:25:09 by jchae             #+#    #+#             */
/*   Updated: 2021/02/24 23:25:11 by jchae            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putnbr(int nb)
{
	int a;
	int b;
	int c;

	c = -2147483648;
	if (nb > 0)
	{
		a = nb / 10;
		b = nb % 10;
		ft_putchar('0' + a);
		ft_putchar('0' + b);
	}
	else if (nb == c)
	{
		write(1, "–2147483648", 13);
	}
	else
	{
		nb *= -1;
		a = nb / 10;
		b = nb % 10;
		ft_putchar('-');
		ft_putchar('0' + a);
		ft_putchar('0' + b);
	}
}
