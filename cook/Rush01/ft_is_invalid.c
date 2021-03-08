/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_invalid.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkang <mkang@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/06 14:53:34 by mkang             #+#    #+#             */
/*   Updated: 2021/03/06 18:59:01 by mkang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>

int		ft_count_words(char *str);

int		ft_strlen(char *str)
{
	int	length;

	length = 0;
	while (str[length])
		length += 1;
	return (length);
}

bool	ft_is_invalid_length(int length)
{
	int	valid_size;

	valid_size = 16;
	while (valid_size <= 36)
	{
		if (length * 4 == valid_size)
			return (false);
		valid_size += 4;
	}
	return (true);
}

bool	ft_is_invalid(char **words, int length)
{
	if (ft_is_invalid_length(length))
		return (true);
	while (*words)
	{
		if (ft_strlen(*words) != 1)
			return (true);
		if (**words < '1' || **words > '0' + length)
			return (true);
		words++;
	}
	return (false);
}
