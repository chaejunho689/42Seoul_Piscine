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
				return (&str[i]);
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
	char *string1;
	char *string2;

	char str1[] = "cd";
	char str2[] = "abcde";
	string1 = ft_strstr(str2, str1);
	printf("제가쓴거 : %s\n", string1);
	string2 = strstr(str2, str1);
	printf("정답: %s\n", string2);
	return 0;
}
