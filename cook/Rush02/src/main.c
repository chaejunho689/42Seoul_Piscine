/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkim <nkim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/14 23:13:47 by nkim              #+#    #+#             */
/*   Updated: 2021/03/14 23:13:48 by nkim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush.h"

int	main(int argc, char **argv)
{
	char		*tmp_input;
	s_numdict	*dict;

	tmp_input = 0;
	dict = 0;
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
	print_result(tmp_input, dict, argc);
	return (0);
}
