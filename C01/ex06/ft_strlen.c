#include <unistd.h>

int	ft_strlen(char *str)
{
	int i;
	i = 0;

	while(str[i] != '\0')
	{
		i++;
	}
	return (i);
}

int 	main(void)
{
	int len;
	char str[] = "Hello";
	len = ft_strlen(str) + '0';
	write(1, &len, 1);
	return 0;
}
