/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchae <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/17 12:04:29 by jchae             #+#    #+#             */
/*   Updated: 2021/03/17 16:11:48 by jchae            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int		ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

int		is_valid_base(char *str)
{
	int		i;
	int		j;

	i = 0;
	while (str[i])
	{
		j = i + 1;
		while (str[j])
		{
			if ((str[i] == str[j]) || str[i] == '+' || str[i] == '-')
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

void	ft_putnbr_base(int nbr, char *base)
{
	int base_nb;

	base_nb = ft_strlen(base);
	if (base_nb <= 1)
		return ;
	if (is_valid_base(base))
	{
		if (nbr == -2147483648)
		{
			ft_putnbr_base(nbr / base_nb, base);
			write(1, &(base[-(nbr % base_nb)]), 1);
			return ;
		}
		if (nbr < 0)
		{
			nbr = -nbr;
			ft_putchar('-');
		}
		if (nbr >= base_nb)
		{
			ft_putnbr_base(nbr / base_nb, base);
		}
		ft_putchar(base[nbr % base_nb]);
	}
}
