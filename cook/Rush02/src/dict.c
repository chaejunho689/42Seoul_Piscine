/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dict.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkim <nkim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/14 15:32:24 by nkim              #+#    #+#             */
/*   Updated: 2021/03/14 23:01:52 by nkim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush.h"

void		set_upper_hundred(int number_len, char *printable, s_numdict *dict)
{
	size_t	position;

	if (dict->unit == 0)
	{
		dict->unit = malloc_initialize(14 * sizeof(char *));
		dict->unit[0] = malloc_initialize(1);
		dict->unit_size = 14;
	}
	position = (number_len - 1) / 3;
	if (position > (dict->unit_size - 2))
	{
		dict->unit =
			ft_realloc(dict->unit,
						dict->unit_size * sizeof(char *),
						(dict->unit_size + (position - (dict->unit_size - 2))) *
							sizeof(char *));
		check_overlap_data(
			(char **)&(dict->unit_size),
			(char *)(dict->unit_size + (position - (dict->unit_size - 2))));
	}
	check_overlap_data((char **)&(dict->unit[position]), printable);
}

void		set_struct(char *number, char *printable, s_numdict *dict)
{
	int	number_len;

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

int			open_file(char *file_path)
{
	int	fd;

	fd = open(file_path, O_RDONLY);
	if (fd == -1)
		return (FALSE);
	return (fd);
}

s_numdict	*build_dict(char *file_path)
{
	int			fd;
	char		*line;
	s_numdict	*dict;

	fd = open_file(file_path);
	if (fd == FALSE)
		return (0);
	dict = (s_numdict *)malloc_initialize(sizeof(s_numdict));
	while (TRUE)
	{
		line = read_line(fd);
		if (ft_strlen(line) == 0 || !(is_valid_line(line)))
		{
			if (!(is_valid_line(line)) && ft_strlen(line) != 0)
			{
				free_dict(dict);
				dict = 0;
			}
			free(line);
			close(fd);
			return (dict);
		}
		line_to_struct(line, dict);
		free(line);
	}
}
