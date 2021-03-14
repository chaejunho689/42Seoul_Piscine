/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkim <nkim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/14 15:31:42 by nkim              #+#    #+#             */
/*   Updated: 2021/03/14 15:32:03 by nkim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush.h"

int	is_valid_input(char *input)
{
	int	i;

	if (input[0] == 0)
		return (FALSE);
	i = 0;
	while (input[i] != 0)
	{
		if (!(input[i] >= '0' && input[i] <= '9'))
			return (FALSE);
		i++;
	}
	return (TRUE);
}
