/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchae <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/11 17:10:21 by jchae             #+#    #+#             */
/*   Updated: 2021/03/14 20:20:09 by jchae            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int	ft_strlen(char *base)
{
	int i;

	i = 0;
	while (base[i] != '\0')
	{
		i++;
	}
//	printf("%d진수\n", i);
	return (i);
}

void	ft_putput(int sutja, int base_len)
{
	if (sutja > base_len)
	{
		ft_putput(sutja / base_len, base_len);
	}
	ft_putchar(48 + sutja % base_len);
}

void	ft_putnbr_base(int nbr, char *base)
{
	int base_len;

	base_len = ft_strlen(base);	
	if (nbr < 0 )
	{
		nbr *= - 1;
		ft_putchar('-');
		ft_putput(nbr, base_len);
	}
	else if(nbr >= base_len)
	{
		ft_putput(nbr, base_len);
	}
	else
		ft_putchar(48 + nbr);
}

int	main(void)
{
	int nbr = 100;
	char base[] = "01";
	printf("입력값은 %d\n", nbr);
	ft_putnbr_base(nbr, base);
	return (0);
}
