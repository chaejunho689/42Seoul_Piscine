/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkim <nkim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/14 15:32:44 by nkim              #+#    #+#             */
/*   Updated: 2021/03/14 23:02:10 by nkim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush.h"

char	*ft_strcat(char *dest, char *src)
{
	int	i;
	int	j;

	i = 0;
	while (dest[i])
	{
		i++;
	}
	j = 0;
	while (src[j])
	{
		dest[i] = src[j];
		i++;
		j++;
	}
	dest[i] = '\0';
	return (dest);
}

char	*check_zero(char *input)
{
	char	*start;
	char	*result;
	int		i;

	start = input;
	if (*start == '0')
	{
		while (*start == '0')
			start++;
	}
	if (!(*start))
		start--;
	result = (char *)malloc_initialize(sizeof(char) * ft_strlen(start) + 1);
	i = 0;
	while (*start)
	{
		result[i] = *start;
		start++;
		i++;
	}
	free(input);
	return (result);
}

char	*strip_str(char *input)
{
	char	*start;
	char	*end;
	char	*result;

	start = input;
	while ((unsigned char)*start == ' ')
		start++;
	if (*start == 0)
		return (malloc_initialize(1));
	end = start + ft_strlen(start) - 1;
	while (end > start && (unsigned char)*end == ' ')
		end--;
	end[1] = 0;
	result = malloc_initialize(end - start + 2);
	ft_strcpy(result, start);
	free(input);
	return (result);
}

char	*read_until_enter(void)
{
	char	buf;
	char	*result;
	int		result_len;

	result = malloc_initialize(1);
	buf = 0;
	while (buf != '\n')
	{
		result_len = ft_strlen(result);
		result = ft_realloc(result, result_len, result_len + 2);
		result[result_len] = buf;
		result[result_len + 1] = 0;
		read(0, &buf, 1);
	}
	return (result);
}
