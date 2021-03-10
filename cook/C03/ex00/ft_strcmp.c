/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchae <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/10 13:59:06 by jchae             #+#    #+#             */
/*   Updated: 2021/03/11 00:36:32 by jchae            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>

int		ft_strcmp(char *s1, char *s2)
{
	int i;
	int j;
	int result;

	i = 0;
	j = 0;
	result = 0;
	while (s1[i] != '\0' || s2[j] != '\0')
	{
		if (s1[i] > s2[j])
			result = 1;
		else if (s1[i] < s2[i])
			result = -1;
		else
		{
			result = 0;
		}
		i++;
		j++;
	}
	return (result);
}

int		main(void)
{
	printf("%d\n", ft_strcmp("", ""));
	printf("%d\n", strcmp("", ""));
	return (0);
}
