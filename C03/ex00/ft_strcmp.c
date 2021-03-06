#include <stdio.h>
#include <string.h>

int 	ft_strcmp(char *s1, char *s2)
{
	int i;
	int j;

	i = 0;
	j = 0;

	while(s1[i] == s2[j])
	{
		i++;
		j++;
		if(s1[i] != s2[j])
		{
			if(s1[i] > s2[j])
				return (1);
			else if(s1[i] < s2[j])
				return (-1);
		}
		if(s1[i] == '\0' || s2[j] == '\0')
			break;
	}
	return 0;
}

int	main()
{
	printf("%d\n", ft_strcmp("123", "123"));
	printf("%d\n", strcmp("123", "123"));
	return 0;
}
