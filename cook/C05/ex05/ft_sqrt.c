int ft_sqrt(int nb)
{
	int i;

	i = 0;
	if (nb < 0)
		return (0);
	else if (nb == 1)
		return (1);
	while(i <= nb / 2)
	{
		if ((i * i) == nb)
		{
			return (i);
		}
		i++;
	}
	return (0);
}

#include <stdio.h>
int	main()
{
	printf("%d", ft_sqrt(16));
	return (0);
}
