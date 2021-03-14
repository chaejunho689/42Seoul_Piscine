/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchae <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/10 18:29:57 by jchae             #+#    #+#             */
/*   Updated: 2021/03/15 06:02:47 by jchae            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include <string.h>

int		ft_strncmp(char *s1, char *s2, unsigned int n)
{
	unsigned int i;
	i = 0;
	
	if(n == 0)
		return (0);
	while (((s1[i] != '\0') && (s2[i] != '\0')) && (i < n) && (s1[i] == n || s2[i] == n))
	{
		if (s1[i] == s2[i])
		{
			i++;
			continue;
		}
		else
			return (s1[i] - s2[i]);
		i++;
	}
	if (s1[0] == '\0' || s2[0] == '\0')
		return (s1[i] - s2[i]);
	return (0);
}

int		main(void)
{
	printf("%d\n", ft_strncmp("", "3", 0));
	printf("%d\n", strncmp("", "3", 0));
	return (0);
}
