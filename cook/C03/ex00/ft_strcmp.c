#include <stdio.h>
#include <string.h>

int		ft_strcmp(char *s1, char *s2)
{
	int i;
	int j;

	i = 0;
	j = 0;	

	while (s1[i] != '\0' || s2[i] != '\0')
	{
		if (s1[i] != s2[i])
			return (s1[i] - s2[i]);
		else
		{
			break;
		}
		i++;
		j++;
	}
	return (0);
}

int	main()
{
	printf("%d\n", ft_strcmp("1", "8"));
	printf("%d\n", strcmp("1", "8"));
	return 0;
}
