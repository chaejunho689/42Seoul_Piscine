/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_interactive_power.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchae <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/17 12:15:49 by jchae             #+#    #+#             */
/*   Updated: 2021/03/17 19:28:07 by jchae            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


int		ft_iterative_power(int nb, int power)
{
	int result;
	int i;

	i = 0;
	result = 1;
	if (power < 0)
		return (0);
	if (power == 1)
		return (1);
	while (i < power)
	{
		result = result * nb;
	}
	i++;
	return (result);
}


#include <unistd.h>
#include <stdio.h>

int         ft_iterative_power(int nb, int power)
{
    int     result;

    result = 1;
    if ((nb == 0 && power !=0) || power < 0)
        return (0);
    if ((power == 0) || (( nb < 0) && (power == 0)))
        return (1);
    else
    {
        while (power > 0)
        {
            result =  nb * result;
            power--;
        }
        return (result);
    }
}

#include <stdio.h>

int	main(void)
{
	printf("10^2 = %d\n", ft_iterative_power(10, 2));
	printf("10^0 = %d\n", ft_iterative_power(10, 0));
	printf("0^0 = %d\n", ft_iterative_power(0, 0));
	printf("10^-1 = %d\n", ft_iterative_power(10, -1));
	printf("10^5 = %d\n", ft_iterative_power(10, 5));
}
