#include "rush.h"

int		is_in_arr(char c, char *arr)
{
	int		i;

	i = 0;
	while (arr[i] != 0)
	{
		if (arr[i] == c)
			return (1);
		i++;
	}
	return (0);
}

int		is_printable(u_int8_t c)
{
	if (c >= ' ' && c <= '~')
		return (1);
	else
		return (0);
}

char	*is_key_valid(char *line, int *validity)
{
	size_t		i;
	int			col;

	i = 0;
	col = 0;
	if (!(is_in_arr(line[0], "0123456789")))
	{
		*validity = 0;
		return (0);
	}
	while (is_in_arr(line[i], "0123456789"))
		i++;
	while (is_in_arr(line[i], ": "))
	{
		if (line[i] == ':')
			col++;
		i++;
	}
	if (col == 1)
	{
		*validity = 1;
		return (&line[i]);
	}
	*validity = 0;
	return (0);
}

char	*is_printable_valid(char *line, int *validity)
{
	size_t		i;
	int			notspace;

	i = 0;
	notspace = 0;
	while (is_printable(line[i]))
	{
		if (line[i] != ' ')
			notspace++;
		i++;
	}
	if (notspace == 0 && line[i - 1] == ' ')
	{
		*validity = 0;
		return (0);
	}
	if (line[i] == 0 || line[i] == '\n')
	{
		*validity = 1;
		return (&line[i]);
	}
	else
		*validity = 0;
	return (0);
}

int		is_valid_line(char *line)
{
	char		*aftercol;
	int			validity;

    validity = FALSE;
	aftercol = is_key_valid(line, &validity);
	if (validity == FALSE)
		return (validity);
	is_printable_valid(aftercol, &validity);
	return (validity);
}