#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_hexchar(char *hexchar)
{
	int i;

	hexchar = "123456789abcdef"
	if(i < 16)
	ft_putchar(ft_hexchar(hexchar[i]) / 16);
	ft_putchar(ft_hexchar(hexchar[i]) % 16);

}

void	ft_putstr_non_printable(char *str)
{
	int i;

	i = 0;
	while (str[i] < 32 && str[i] == 127)
	{
		str[i] = ft_putchar('\\');
		ft_hexchar(str[i]);
	}
}

int		main(void)
{
	int	i;
	i = 0;
	
	return (0);
}
