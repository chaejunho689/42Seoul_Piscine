#include <stdio.h>

int 	ft_str_is_numeric(char *str)
{
	int i;
	int j;

	i = 0;
	while(str[i] != '\0')
	{
		if(48 <= str[i] && str[i] <=  57)
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
	char tab[6] = "0259";
	ft_str_is_numeric(&tab[0]);
	printf("%d", ft_str_is_numeric(tab));
	return (0);
}
