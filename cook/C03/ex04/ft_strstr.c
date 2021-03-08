#include <unistd.h>
#include <string.h>

char	*ft_strstr(char *str, char *to_find)
{
	int i;
	int j;

	i = 0;
	j = 0;
	if(to_find[0] == '\0')
		return (str);
	while (str[i] != '\0')
	{
		if(str[i] == to_find[j])
		{
				i++;
				j++;
		}
		else if (to_find[j] == '\0')
				return (&str[i - j]);
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

	char str1[] = "";
	char str2[] = "123";
	string = ft_strstr(str1, str2);
	printf("%s\n", string);
	string = strstr(str1, str2);
	printf("%s\n", string);
	return 0;
}
