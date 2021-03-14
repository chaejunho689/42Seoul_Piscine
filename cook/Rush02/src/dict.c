/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dict.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkim <nkim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/14 15:32:24 by nkim              #+#    #+#             */
/*   Updated: 2021/03/14 15:32:26 by nkim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush.h"

int			ft_atoi(char *str)
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

char		*read_line(int fd)
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

char		*extract_number(char *line, int line_len)
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

char		*extract_printable(char *line, int line_len)
{
	char	*printable;
	int i;
	int	j;

	printable = malloc_initialize(line_len);
	i = 0;
	while (i < line_len)
		if (line[i++] == ':') break ;
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

void	set_under_hundred(char *number, int number_len, char *printable, s_numdict *dict)
{
	int num;
	num = ft_atoi(number);
	if (number_len == 1)
	{
		if (num == 0)
		{
			dict->zero = printable;
			dict->numbers[0] = malloc_initialize(1);
		}
		else
			dict->numbers[num] = printable;
	}
	if (number_len == 2)
	{
		if (num / 10 == 1)
			dict->teen[num % 10] = printable;
		else
			dict->tens[num / 10] = printable;
	}
	if (num == 100)
		dict->hundreds = printable;
}

void	set_upper_hundred(int number_len, char *printable, s_numdict *dict)
{
	int	position;

	if (dict->unit == 0)
		{
			dict->unit = malloc_initialize(14 * sizeof(char *));
			dict->unit[0] = malloc_initialize(1);
			dict->unit_size = 14;
		}
		position = (number_len - 1) / 3;
		if (position > (dict->unit_size - 2))
		{
			dict->unit = ft_realloc(
				dict->unit,
				dict->unit_size * sizeof(char *),
				(dict->unit_size + (position - (dict->unit_size - 2))) *
					sizeof(char *));
			dict->unit_size =
				dict->unit_size + (position - (dict->unit_size - 2));
		}
		dict->unit[position] = printable;
}

void		set_struct(char *number, char *printable, s_numdict *dict)
{
	int	number_len;
	int	num;
	
	number_len = ft_strlen(number);
	if (number_len <= 3) 
		set_under_hundred(number, number_len, printable, dict);

	else if (number_len > 3 && number[0] == '1') 
		set_upper_hundred(number_len, printable, dict);
}

void		line_to_struct(char *line, s_numdict *dict)
{
	char	*number;
	char	*printable;
	int		line_len;

	line_len = ft_strlen(line);
	number = extract_number(line, line_len);
	if (number)
	{
		printable = extract_printable(line, line_len);
		if (printable)
			set_struct(number, printable, dict);
		free(number);
	}
}

s_numdict	*build_dict(char *file_path)
{
	int			fd;
	char		*line;
	s_numdict	*dict;

	dict = (s_numdict *)malloc_initialize(sizeof(s_numdict));
	fd = open(file_path, O_RDONLY);
	if (fd == -1)
	{
		ft_putchar("Dict Error\n");
		return (FALSE);
	}
	while (TRUE)
	{
		line = read_line(fd);
		if (ft_strlen(line) == 0)
			break ;
		if (!(is_valid_line(line)))
			return 0;
		line_to_struct(line, dict);
	}
	close(fd);
	return (dict);
}
