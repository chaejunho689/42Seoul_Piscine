/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchae <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/10 19:44:13 by jchae             #+#    #+#             */
/*   Updated: 2021/03/10 19:49:50 by jchae            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

unsigned int	ft_result(int dest_size, int src_size, int size)
{
	unsigned int result;

	if (size <= dest_size)
		result = src_size + size;
	else
		result = src_size + dest_size;
	return (result);
}

unsigned int	ft_strlcat(char *dest, char *src, unsigned int size)
{
	unsigned int result;
	unsigned int dest_size;
	unsigned int src_size;

	result = 0;
	dest_size = 0;
	src_size = 0;
	while (dest[dest_size] != '\0')
		dest_size++;
	while (src[src_size] != '\0')
		src_size++;
	result = ft_result(dest_size, src_size, size);
	while ((src[src_size] != '\0') && (size - dest_size - 1))
	{
		dest[dest_size] = src[src_size];
		dest_size++;
		src_size++;
	}
	dest[dest_size] = '\0';
	return (result);
}
