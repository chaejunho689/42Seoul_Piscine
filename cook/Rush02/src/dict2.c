/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dict2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkim <nkim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/14 23:07:02 by nkim              #+#    #+#             */
/*   Updated: 2021/03/14 23:07:06 by nkim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush.h"

char	*read_line(int fd)
{
	char	buf;
	char	*result;
	int		read_result;
	int		loop;

	buf = 0;
	loop = 0;
	result = malloc_initialize(1);
	while (buf != '\n')
	{
		read_result = read(fd, &buf, 1);
		if (read_result == 0)
			break ;
		if (read_result == -1)
			ft_putchar("Dict Error\n");
		result = ft_realloc(result, loop + 1, loop + 2);
		result[loop] = buf;
		result[loop + 1] = 0;
		loop++;
	}
	return (result);
}

char	*extract_number(char *line, int line_len)
{
	int		i;
	char	*number;

	number = malloc_initialize(line_len);
	i = 0;
	while (i < line_len)
	{
		if (line[i] == ':')
		{
			number = strip_str(number);
			number = check_zero(number);
			break ;
		}
		number[i] = line[i];
		i++;
	}
	if (i == line_len)
	{
		free(number);
		return (0);
	}
	return (number);
}

char	*extract_printable(char *line, int line_len)
{
	char	*printable;
	int		i;
	int		j;

	printable = malloc_initialize(line_len);
	i = 0;
	while (i < line_len)
		if (line[i++] == ':')
			break ;
	j = 0;
	while (i < line_len)
	{
		if (line[i] == '\n')
		{
			printable = strip_str(printable);
			break ;
		}
		printable[j++] = line[i++];
	}
	if (i == line_len)
	{
		free(printable);
		return (0);
	}
	return (printable);
}

void	set_under_hundred(char *n, int n_len, char *printable, s_numdict *dict)
{
	int	num;

	num = ft_atoi(n);
	if (n_len == 1)
	{
		if (num == 0)
		{
			check_overlap_data(&(dict->zero), printable);
			dict->numbers[0] = malloc_initialize(1);
		}
		else
			check_overlap_data(&(dict->numbers[num]), printable);
	}
	if (n_len == 2)
	{
		if (num / 10 == 1)
			check_overlap_data(&(dict->teen[num % 10]), printable);
		else
			check_overlap_data(&(dict->tens[num / 10]), printable);
	}
	if (num == 100)
		check_overlap_data(&(dict->hundreds), printable);
}
