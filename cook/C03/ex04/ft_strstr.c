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
		if(str[i + j] == to_find[j])
		{
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

	char str1[] = "banana";
	char str2[] = "applebbananaapple";
	string = ft_strstr(str2, str1);
	if (string)
		printf("ft: %s\n", string);
	string = strstr(str2, str1);
	if (string)
		printf("std: %s\n", string);
	return 0;
}
