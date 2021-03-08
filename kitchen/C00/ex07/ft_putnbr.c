/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchae <jchae@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/24 23:25:09 by jchae             #+#    #+#             */
/*   Updated: 2021/03/08 15:26:09 by jchae            ###   ########.fr       */
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
