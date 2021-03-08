#include <stdio.h>

int		ft_str_is_lowercase(char *str)
{
	int i;
	int j;

	i = 0;
	while(str[i] != '\0')
	{
		if(97 <= str[i] && str[i] <= 122)
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
	char tab[6] = "abcd";
	ft_str_is_lowercase(&tab[0]);
	printf("%d", ft_str_is_lowercase(tab));
	return 0;
}
