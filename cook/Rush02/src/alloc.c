/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   alloc.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkim <nkim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/14 23:01:28 by nkim              #+#    #+#             */
/*   Updated: 2021/03/14 23:13:32 by nkim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush.h"

void	initialize(void *pointer, int size)
{
	int	i;

	i = -1;
	while (++i < size)
		*((char *)pointer + i) = 0;
}

void	*malloc_initialize(unsigned int size)
{
	void	*tmp;

	tmp = malloc(size);
	initialize(tmp, size);
	return (tmp);
}

void	*ft_realloc(void *buf, size_t before_size, size_t after_size)
{
	size_t	i;
	uint8_t	*src;
	uint8_t	*dst;

	src = (uint8_t *)buf;
	dst = (uint8_t *)malloc_initialize(after_size);
	i = 0;
	while (i < before_size)
	{
		dst[i] = src[i];
		i++;
	}
	free(buf);
	return (void *)dst;
}
