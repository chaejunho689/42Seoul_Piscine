/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchae <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/22 18:43:57 by jchae             #+#    #+#             */
/*   Updated: 2021/03/08 15:24:10 by jchae            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putput(int sutja)
{
	if (sutja > 9)
	{
		ft_putput(sutja / 10);
	}
	ft_putchar(48 + sutja % 10);
}

void	ft_putnbr(int nb)
{
	if (nb == -2147483648)
	{
		write(1, "-2147483648", 11);
	}
	else if (nb < 0)
	{
		nb *= -1;
		ft_putchar('-');
		ft_putput(nb);
	}
	else if (nb > 9)
	{
		ft_putput(nb);
	}
	else if (nb <= 9)
	{
		ft_putchar('0' + nb);
	}
	else
	{
		write(1, "0", 1);
	}
}

int		main(void)
{
	int result;
	result = 2147483647;
	ft_putnbr(result);
	return (0);
}
