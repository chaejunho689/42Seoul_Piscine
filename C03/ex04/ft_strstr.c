#include <unistd.h>
#include <string.h>

char	*ft_strstr(char *str, char *to_find)
{
	char *ptr;
	int i;
	int j;
	int save;

	i = 0;
	j = 0;

	if(to_find[0] == '\0')
		return (str);

	while (str[i] != '\0')
	{
		if(str[i] == to_find[j])
		{
			if (str[i] != '\0' && to_find[j] != '\0')
			{
				i++;
				j++;
			}
			if(to_find[j] == '\0')
				return (&str[i - j]);
		}
		else
		{
			j = 0;
			i++;
		}
	}
	return (0);
}

#include <stdio.h>

int 	main()
{
	char *string;

	char str1[] = "Hi Hello Annyong";
	char str2[] = "Hello";
	string = ft_strstr(str1, str2);
	printf("%s\n", string);
	string = strstr(str1, str2);
	printf("%s\n", string);
	return 0;
}
