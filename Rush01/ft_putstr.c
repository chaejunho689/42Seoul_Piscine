#include <unistd.h>

void	ft_putstr(char *str)
{
	int i;

	while(str[i] != '\0')
	{
		write(1, &str[i++], 1);
		i++;
	}
}

void	ft_putchar(char c)
{
	write(1, &c, 1);
}
