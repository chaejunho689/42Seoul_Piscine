/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_boolean.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchae <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/18 05:02:59 by jchae             #+#    #+#             */
/*   Updated: 2021/03/18 06:29:57 by jchae            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_BOOLEAN_H
# define FT_BOOLEAN_H
# include <unistd.h>

# define EVEN(nbr) 	nbr % 2 == 0
# define EVEN_MSG 	"I have a pair number of arguments.\n"
# define ODD_MSG 	"I have an impair number of arguments.\n"
# define TRUE 		1
# define FALSE 		0
# define SUCCESS 	0

typedef int	t_bool;
#endif
