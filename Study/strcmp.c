#include <stdio.h>
#include <string.h>
#include <unistd.h>

int		ft_strcmp(char *s1, char *s2)
{
	int i;
	int j;
	int result;

	i = 0;
	j = 0;
	while (s1[i] != '\0' || s2[j] != '\0')
	{
		if (s1[i] > s2[j])
			result = s1[i] - s2[j];
		else if (s1[i] < s2[i])
			result = -s1[i] - s2[j];
		else
		{
			result = 0;
		}
		i++;
		j++;
	}
	return (result);
}

int	main(void)
{
	char s1[31];
	char s2[31];

	scanf("%s" "%s", s1, s2);
	printf("%d", ft_strcmp(s1, s2));
	return (0);
}
