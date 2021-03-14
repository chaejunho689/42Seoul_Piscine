/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchae <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/15 06:14:29 by jchae             #+#    #+#             */
/*   Updated: 2021/03/15 06:20:43 by jchae            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int				ft_strlen(char *str)
{
	int i;

	i = 0;
	while (str[i] != '\0')
	{
		i++;
	}
	return (i);
}

unsigned int	ft_strlcat(char *dest, char *src, unsigned int size)
{
	unsigned int dest_size;
	unsigned int src_size;
	unsigned int j;
	unsigned int save_src_size;
	unsigned int save_dest_size;

	src_size = 0;
	dest_size = ft_strlen(dest);
	save_src_size = ft_strlen(src);
	save_dest_size = ft_strlen(dest);
	j = size - dest_size - 1;
	if (save_dest_size < size)
	{
		while ((src[src_size] != '\0') && (src_size < j))
		{
			dest[dest_size] = src[src_size];
			dest_size++;
			src_size++;
		}
		dest[dest_size + 1] = '\0';
		return (save_src_size + save_dest_size);
	}
	else
		return (save_src_size + size);
}
