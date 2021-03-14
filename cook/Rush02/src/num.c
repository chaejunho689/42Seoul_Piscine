/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   num.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkim <nkim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/14 15:32:11 by nkim              #+#    #+#             */
/*   Updated: 2021/03/14 15:32:16 by nkim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush.h"

char	*g_print_buf;

void	add_print_buf(char *str)
{
	int	print_buf_len;

	print_buf_len = ft_strlen(g_print_buf);
	g_print_buf = ft_realloc(
		g_print_buf, print_buf_len, print_buf_len + ft_strlen(str) + 2);
	ft_strcat(g_print_buf, str);
	ft_strcat(g_print_buf, " ");
}

uint8_t	*input_to_int_arr(char *input, size_t input_len)
{
	uint8_t	*num;

	int i, shift_num;
	num = (uint8_t *)malloc_initialize(sizeof(uint8_t) * input_len);
	i = 0;
	shift_num = 0;
	if (input_len % 3)
		shift_num = 3 - (input_len % 3);
	while (input[i])
	{
		num[i + shift_num] = input[i] - '0';
		i++;
	}
	return (num);
}

void	print_term(int num, s_numdict *dict)
{
	if (num / 100 != 0)
	{
		add_print_buf(dict->numbers[num / 100]);
		add_print_buf(dict->hundreds);
		num %= 100;
	}
	if (num / 10 != 0)
	{
		if (num / 10 == 1)
		{
			add_print_buf(dict->teen[num % 10]);
			return ;
		}
		else
			add_print_buf(dict->tens[num / 10]);
		num %= 10;
	}
	if (num)
		add_print_buf(dict->numbers[num]);
}

void	print_numbers(uint8_t *input, size_t input_len, s_numdict *dict)
{
	int	i;
	int	tmp_num;

	i = 0;
	while (i < input_len)
	{
		tmp_num = input[i] * 100 + input[i + 1] * 10 + input[i + 2];
		if (tmp_num > 0)
		{
			if (dict->unit_size - 2 < (input_len - 1) / 3)
			{
				ft_putchar("Dict Error\n");
				return ;
			}
			print_term(tmp_num, dict);
			add_print_buf(dict->unit[(input_len - 1 - i) / 3]);
		}
		i += 3;
	}
	if (tmp_num == 0)
		add_print_buf(dict->zero);
}

void	free_dict(s_numdict *dict)
{
	int	i;

	free(dict->zero);
	free(dict->hundreds);
	i = 0;
	while (i < 10)
	{
		if (dict->numbers[i])
			free(dict->numbers[i]);
		if (dict->teen[i])
			free(dict->teen[i]);
		if (dict->tens[i])
			free(dict->tens[i]);
		i++;
	}
	i = 0;
	while (i < dict->unit_size)
	{
		if (dict->unit[i])
			free(dict->unit[i]);
		i++;
	}
	free(dict->unit);
	free(dict);
}

void print_result(char *tmp_input, s_numdict *dict, int argc)
{
	uint8_t		*input;
	size_t		input_len;

	g_print_buf = malloc_initialize(1);
	input_len = ft_strlen(tmp_input);
	input = input_to_int_arr(tmp_input, input_len);
	print_numbers(input, input_len, dict);
	g_print_buf = strip_str(g_print_buf);
	write(1, g_print_buf, ft_strlen(g_print_buf));
	write(1, "\n", 1);

	if (argc == 1)
		free(tmp_input);
	free(input);
	free(g_print_buf);
	free_dict(dict);
}

int		main(int argc, char **argv)
{
	char		*tmp_input;
	s_numdict	*dict;

	if (argc < 3)
	{
		if (argc == 1)
			tmp_input = read_until_enter();
		if (argc == 2)
			tmp_input = argv[1];
		dict = build_dict(DEFAULT_DICT_FILE);
	}
	else if (argc == 3)
	{
		tmp_input = argv[2];
		dict = build_dict(argv[1]);
	}
	if (argc >= 4 || !(dict) || !(is_valid_input(tmp_input)))
	{
		if (argc >= 4)
			ft_putchar("Error\n");
		else
			ft_putchar("Dgggct Error\n");
	}
	print_result(tmp_input, dict, argc);
	while(1)
	{}
	return (0);
}