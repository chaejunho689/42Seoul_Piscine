#include <unistd.h>
#include <stdio.h>

void ft_putchar(char c)
{
	c = '1';
	write(1, &c, 1);
}

int main()
{
	char c;
	ft_putchar(c);
	return 0;
}
