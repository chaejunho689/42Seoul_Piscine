/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkim <nkim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/14 15:32:40 by nkim              #+#    #+#             */
/*   Updated: 2021/03/14 23:17:22 by nkim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
//#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define DEFAULT_DICT_FILE "numbers.dict"
#define TRUE 1
#define FALSE 0
typedef unsigned char	uint8_t;
// typedef unsigned int size_t;

typedef struct			numdict
{
	char				*zero;
	char				*hundreds;
	char				*numbers[10];
	char				*teen[10];
	char				*tens[10];
	char				**unit;
	size_t				unit_size;
}						s_numdict;


int		is_valid_input(char *input);
void	check_overlap_data(char **dic, char *printable);

int		is_in_arr(char c, char *arr);
int		is_printable(u_int8_t c);
char	*is_key_valid(char *line, int *validity);



// void					check_overlap_data(char **dic, char *printable);
// void					print_result(char *tmp_input, s_numdict *dict, int argc);
// void					free_dict(s_numdict *dict);
// void					print_numbers(uint8_t *input, size_t input_len, s_numdict *dict);
// void					print_term(int num, s_numdict *dict);
// uint8_t					*input_to_int_arr(char *input, size_t input_len);
// void					add_print_buf(char *str);
// int						is_valid_line(char *line);
// s_numdict				*build_dict();
// int						is_valid_input(char *input);
// char					*ft_strcpy(char *dest, char *src);
// void					initialize(void *pointer, int size);
// void					*malloc_initialize(unsigned int size);
// void					*ft_realloc(void *buf, size_t before_size, size_t after_size);
// void					ft_putchar(char *str);
// void					ft_putchar_space(char *str);
// size_t					ft_strlen(char *str);
// char					*ft_strcat(char *dest, char *src);
// char					*strip_str(char *input);
// char					*check_zero(char *input);
// char					*read_until_enter();
