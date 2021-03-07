#include <stdio.h>
#include <unistd.h>

char 	*ft_strcapitalize(char *str)
{
	int i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] >= 'a' || str[





		{
			
		}
		i++;
	}
	return (str);
}

int	main(void)
{
	char *str = "Hello";
	printf("%s", ft_strcapitalize(str));
	return (0);
}
