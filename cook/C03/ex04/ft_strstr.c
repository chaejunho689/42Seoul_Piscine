/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchae <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/15 06:13:48 by jchae             #+#    #+#             */
/*   Updated: 2021/03/15 18:48:48 by jchae            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strstr(char *str, char *to_find)
{
	int i;
	int j;

	i = 0;
	j = 0;
	if (to_find[0] == '\0')
		return (str);
	while (str[i] != '\0')
	{
		if (str[i + j] == to_find[j] && to_find[j] != '\0')
		{
			j++;
		}
		else if (to_find[j] == '\0')
			return (&str[i]);
		else
		{
			j = 0;
			i++;
		}
	}
	return (0);
}
