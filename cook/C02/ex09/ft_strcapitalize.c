#include <stdio.h>
#include <unistd.h>

void	ft_flag(char *str, int *flag)
{
	int i;

	i = 0;
	if (str[i] >= 'a' && str[i] <= 'z')
	{
		if(*flag == 1)
		{
			str[i] = str[i] - 32;
			*flag = 0;
		}
	}
	else if (str[i] >= 'A' && str[i] <= 'Z')
	{
		if (*flag == 0)
		{
			str[i] = str[i] + 32;
			*flag = 0;
		}
	}
	else if (str[i] >= '0' && str[i] <= '9')
		{
			*flag = 0;
		}
	else
		*flag = 1;
}

char 	*ft_strcapitalize(char *str)
{
	int i;
	int flag;

	i = 0;
	flag = 1;
	while(str[i] != '\0')
	{
		ft_flag(&str[i], &flag);
		i++;
	}
	return (str);
}

int	main(void)
{
	char str[] = "salut, comment tu vas ? 42mots quarante-deux; cinquante+et+un";
	printf("%s", ft_strcapitalize(str));
	return (0);
}
