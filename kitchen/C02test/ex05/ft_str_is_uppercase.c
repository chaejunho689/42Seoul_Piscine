/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_uppercase.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchae <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/15 16:29:03 by jchae             #+#    #+#             */
/*   Updated: 2021/03/15 16:29:19 by jchae            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_str_is_uppercase(char *str)
{
	int i;
	int j;

	i = 0;
	if (str[0] == '\0')
	{
		j = 1;
	}
	while (str[i] != '\0')
	{
		if (65 <= str[i] && str[i] <= 90)
		{
			i++;
			j = 1;
		}
		else
		{
			j = 0;
			break ;
		}
	}
	return (j);
}
