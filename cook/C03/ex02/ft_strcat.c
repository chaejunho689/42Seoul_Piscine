/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strcat.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchae <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/10 19:34:55 by jchae             #+#    #+#             */
/*   Updated: 2021/03/15 00:51:06 by jchae            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdio.h>
#include <stdlib.h>

char	*ft_strcat(char *dest, char *src)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (dest[i] != '\0')
	{
		i++;
	}
	while (src[j] != '\0')
	{
		dest[i] = src[j];
		i++;
		j++;
	}
	dest[i] = '\0';
	return (dest);
}

int 	main(void)
{
	char *dest = malloc(sizeof(char) * 11); // 말록은 널값이 들어가야하므로 1 크기를 더 줌
	for (int i = 0; i < 5; i++)
		dest[i] = 'a';
	dest[5] = '\0';
	dest = ft_strcat(dest, "12345");
	printf("%s\n", dest);
	
	char *d2 = malloc(sizeof(char) * 11);
	for (int i = 0; i < 5; i++)
		d2[i] = 'b';
	d2[5] = '\0';
	dest = strcat(d2, "54321");
	printf("%s\n", dest);
	return 0;
}
