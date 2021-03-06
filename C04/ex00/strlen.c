#include <stdio.h>
int	ft_strlen(char *str)
{

	int str_length;
	str_length = 0;
	while(str[str_length])
	{
		str_length++;
	}
	return (str_length);
}

int 	main()
{
	printf("%d", ft_strlen("Hello"));
	return 0;
}
