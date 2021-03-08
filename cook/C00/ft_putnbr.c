#include <stdio.h>
#include <unistd.h>

void 	ft_putchar()
{
	write(1, &c, 1);
}

void	ft_putnbr (int nb)
{
	if (nb == -2147483648)
	{
		write(1, "-2147483648", 11);
	}
	else if (nb > 0)
	{
		putchar(1, 
	}
}

int		main(void)
{
	int nb;
	ft_putnbr (nb);
	return 0;
}
