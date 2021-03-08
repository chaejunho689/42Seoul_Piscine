#include <stdio.h>
#include <unistd.h>

char 	*ft_strcapitalize(char *str)
{
	int i;

	i = 0;
	if(str[i] >= 'a' && str[i] <= 'z')
	{
		str[i] = str[i] - 32;
	}
	while (str[i] != '\0')
	{
		if(!((str[i] >= 'a' && str[i] <= 'z') ||
				(str[i] >= 'A' && str[i] <= 'Z') ||
				(str[i] >= '0' && str[i] <= '9')))
		{
			i++;
		}
		else
		{
	   		if((str[i] >= 'A') >= (str[i] <= 'Z'))
				str[i] = str[i] + 32;
		}
	}
	return (str);
}

int	main(void)
{
	char *str = "Hello";
	printf("%s", ft_strcapitalize(str));
	return (0);
}
