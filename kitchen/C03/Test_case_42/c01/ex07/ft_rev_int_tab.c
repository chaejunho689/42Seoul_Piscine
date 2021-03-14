/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rev_int_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchae <jchae@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/01 15:20:41 by jchae             #+#    #+#             */
/*   Updated: 2021/03/08 16:58:56 by jchae            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_rev_int_tab(int *tab, int size)
{
	int i;
	int j;
	int save;

	i = 0;
	j = size - 1;
	while (i < (size / 2))
	{
		save = tab[i];
		tab[i] = tab[j];
		tab[j] = save;
		i++;
		j--;
	}
}
