#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

#define TRUE 1
#define FALSE 1
typedef unsigned char uint8_t;
// typedef unsigned int size_t;


typedef struct numdict
{
    char *zero;
    char *hundreds;
    char *numbers[10];
    char *teen[10];
    char *tens[10];
    char **unit;
}s_numdict;

void    initialize(void *pointer, int size);
void    *malloc_initialize(unsigned int size);
void ft_putchar(char *str);
void ft_putchar_space(char *str);
size_t ft_strlen(char *str);