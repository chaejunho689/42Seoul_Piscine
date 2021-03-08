#include <stdio.h>

int		ft_str_is_uppercase(char *str)
{
	int i;
	int j;

	i = 0;
	if(str[0] == '\0')
	{
		j = 1;
	}
	while(str[i] != '\0')
	{
		if(65 <= str[i] && str[i] <= 90)
		{
			i++;
			j = 1;
		}
		else
		{
			j = 0;
			break;
		}
	}
	return (j);
}

int 	main(void)
{
	char tab[6] = "ABC";
	ft_str_is_uppercase(&tab[0]);
	printf("%d", ft_str_is_uppercase(tab));
	return 0;
}
