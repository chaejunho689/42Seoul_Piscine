/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchae <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/08 19:59:47 by jchae             #+#    #+#             */
/*   Updated: 2021/03/08 23:52:19 by jchae            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include <string.h>

unsigned int	ft_strlcat(char *dest, char *src, unsigned int size)
{
	unsigned int i;
	unsigned int j;
	unsigned int result;
	unsigned int dest_size;
	unsigned int src_size;

	i = 0;
	j = 0;
	while (dest[i] != '\0')
	{
		i++;
		dest_size = i;
	}
	while (src[j] != '\0')
	{
		j++;
		src_size = j;
	}
	while (src[j] != '\0' && j < (size - 1))
	{
		dest[i] = src[j];
		i++;
		j++;
	}
	dest[i] = '\0';
	if (size < dest_size)
		result = src_size + size;
	else if (size > dest_size)
		result = src_size + dest_size;
	else
		result = dest_size + src_size;
	return (result);
}

int 	main()
{
	char dest[10] = "Hell";
	char src[] = "An";
	printf("%lu", strlcat(dest, src, 7));
	printf("%d", ft_strlcat(dest, src, 7));
	return 0;
}
