/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkang <mkang@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/06 11:52:40 by mkang             #+#    #+#             */
/*   Updated: 2021/03/06 22:24:10 by mkang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>
#include <stdlib.h>

void	ft_strncpy(char *dest, char *src, int size)
{
	while (*src && size--)
		*dest++ = *src++;
	*dest = '\0';
}

bool	ft_is_in_charset(char c, char *charset)
{
	while (*charset)
	{
		if (c == *charset)
			return (true);
		charset++;
	}
	return (false);
}

int		ft_count_words(char *str)
{
	int		count;
	char	*charset;

	charset = " \t\n\v\f\r";
	count = 0;
	while (*str)
	{
		if (!ft_is_in_charset(*str, charset))
		{
			count += 1;
			while (*str && !ft_is_in_charset(*str, charset))
				str++;
		}
		else
			str++;
	}
	return (count);
}

char	**ft_split(char *str)
{
	char	**result;
	char	*from;
	char	*charset;
	int		size;
	int		i;

	charset = " \t\n\v\f\r";
	size = ft_count_words(str);
	result = (char **)malloc(sizeof(char *) * (size + 1));
	result[size] = 0;
	i = 0;
	while (*str)
	{
		if (!ft_is_in_charset(*str, charset))
		{
			from = str;
			while (*str && !ft_is_in_charset(*str, charset))
				str++;
			result[i] = (char *)malloc(sizeof(char) * (str - from + 1));
			ft_strncpy(result[i++], from, str - from);
		}
		else
			str++;
	}
	return (result);
}
