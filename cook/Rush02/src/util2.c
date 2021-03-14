/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkim <nkim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/14 23:15:04 by nkim              #+#    #+#             */
/*   Updated: 2021/03/14 23:15:05 by nkim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush.h"

int		ft_atoi(char *str)
{
	int	result;
	int	i;

	i = 0;
	result = 0;
	while (str[i] && str[i] >= '0' && str[i] <= '9')
	{
		result *= 10;
		result += str[i] - '0';
		i++;
	}
	return (result);
}

char	*ft_strcpy(char *dest, char *src)
{
	int	i;

	i = 0;
	while (src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

void	ft_putchar(char *str)
{
	int	i;

	i = -1;
	while (*str)
	{
		write(1, str, 1);
		str++;
	}
}

size_t	ft_strlen(char *str)
{
	size_t	str_len;

	str_len = 0;
	while (str[str_len])
		str_len++;
	return (str_len);
}
