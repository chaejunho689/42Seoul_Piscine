/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_next_prime.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchae <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/17 18:28:34 by jchae             #+#    #+#             */
/*   Updated: 2021/03/17 19:10:21 by jchae            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_is_prime(int nb)
{
	int	i;

	i = 2;
	while (i <= nb / i)
	{
		if (nb % i == 0)
		{
			return (1);
		}
		i++;
	}
	return (0);
}

int	ft_find_next_prime(int nb)
{
	int i;

	if (nb <= 1)
		return (2);
	i = nb;
	while (ft_is_prime(i))
	{
		i++;
	}
	return (i);
}
