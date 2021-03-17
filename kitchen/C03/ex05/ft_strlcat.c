/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchae <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/15 23:44:20 by jchae             #+#    #+#             */
/*   Updated: 2021/03/17 11:46:42 by jchae            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

unsigned int	ft_strlcat(char *dest, char *src, unsigned int size)
{
	unsigned int dest_size;
	unsigned int src_size;
	unsigned int result;

	dest_size = 0;
	src_size = 0;
	while (dest[dest_size] != '\0')
		++dest_size;
	while (src[src_size] != '\0')
		++src_size;
	result = src_size;
	if (size <= dest_size)
		result += size;
	else
		result += dest_size;
	src_size = 0;
	while (src[src_size] != '\0' && dest_size + 1 < size)
	{
		dest[dest_size] = src[src_size];
		dest_size++;
		src_size++;
	}
	dest[dest_size] = '\0';
	return (result);
}
