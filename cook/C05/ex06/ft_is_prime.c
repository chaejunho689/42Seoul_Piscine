int ft_is_prime(int nb)
{
	int i;

	i = 2;
	if (nb <= 1)
		return (0);
	while( nb % i != 0)
	{
		i++;
	}
	if (i == nb)
		return (1);
	else
		return (0);
}

#include <stdio.h>
int	main()
{
	printf("%d", ft_is_prime(-1));
	return 0;
}
