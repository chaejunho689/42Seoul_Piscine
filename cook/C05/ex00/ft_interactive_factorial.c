#include <stdio.h>
#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int	ft_strlen(char *base)
{
	int i;

	i = 0;
	while(base[i] != '\0')
	{
		i++;
	}
	return (i);
}

void	ft_putnbr_base(int nbr, char *base)
{
	int i;
	int len;
	int mod;
	int div;

	len = ft_strlen(base);
	while (nbr != 0)
	{
		div = nbr / len;
		mod = nbr % len;
		nbr = div;
		ft_putchar(base[mod]);
	}

}

int	main()
{
	char *base = "01234";
	ft_putnbr_base(45, base);
	return 0;
}
