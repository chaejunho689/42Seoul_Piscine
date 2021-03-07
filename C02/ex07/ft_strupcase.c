#include <unistd.h>
#include <stdio.h>

char	*ft_strupcase(char *str)
{
	int i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] >= 'a' && str[i] <= 'z')
		{
			str[i] -= 32;
			i++;
		}
		else
			i++;
	}
	return (str);
}

int	main()
{
	int i = 0;
	char arr[15] = "-Hellll-lo=";
	printf("%s", ft_strupcase(arr));
	return 0;
}
