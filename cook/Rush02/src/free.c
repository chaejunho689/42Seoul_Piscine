/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkim <nkim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/14 23:13:41 by nkim              #+#    #+#             */
/*   Updated: 2021/03/14 23:13:43 by nkim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush.h"

void	if_free(void *ptr)
{
	if (ptr)
		free(ptr);
}

void	free_dict(s_numdict *dict)
{
	size_t	i;

	if_free(dict->zero);
	if_free(dict->hundreds);
	i = 0;
	while (i < 10)
	{
		if_free(dict->numbers[i]);
		if_free(dict->teen[i]);
		if_free(dict->tens[i]);
		i++;
	}
	i = 0;
	while (i < dict->unit_size)
	{
		if_free(dict->unit[i]);
		i++;
	}
	if_free(dict->unit);
	if_free(dict);
}
