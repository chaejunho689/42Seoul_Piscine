/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchae <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/10 13:59:06 by jchae             #+#    #+#             */
/*   Updated: 2021/03/11 13:26:04 by desire           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>

int		ft_strcmp(char *s1, char *s2)
{
	int i;
	int result;

	while(s1[i] != '\0' || s2[i] != '\0')
	{
		if(s1[i] != s2[i])
			result = s1[i] - s2[i];
		else
		{
			result = s1[i] - s2[i];
		}
		i++;
	}
	return (result);
}

int		main(void)
{
	printf("%d\n", ft_strcmp("", ""));
	printf("%d\n", strcmp("", ""));
	return (0);
}
