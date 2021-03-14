#include <unistd.h>
#include <stdio.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_hexchar(char c)
{
	char *hexchar;

	hexchar = "123456789abcdef";
	if(*hexchar < 16)
	{
		ft_hexchar(*hexchar / 16);
		ft_hexchar(*hexchar % 16);
	}
	else
		ft_putchar(hexchar[c]);
}

void	ft_putstr_non_printable(char *str)
{
	int i;

	i = 0;
	while (str[i])
	{
		if ((str[i] < 32 && str[i] > 0) || str[i] == 127)
		{	
			ft_putchar('\\');
			if (str[i] < 16)
			{
				ft_putchar('0');
			}
			//ft_hexchar(str[i]);
		}
		else if (str[i] == 0)
			ft_putchar('0');
		else
			ft_putchar(str[i]);
		i++;
	}
}

int		main(void)
{
	char *str = "Coucou\ntu vas bien ?";
	printf("%c", ft_putstr_non_printable(str));
	return (0);
}
