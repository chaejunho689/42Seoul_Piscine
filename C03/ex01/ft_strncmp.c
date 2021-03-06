#include <stdio.h>
#include <unistd.h>
#include <string.h>

int 	ft_strncmp(char *s1, char *s2, unsigned int n)
{
	int i;
	int j;

	i = 0;
	j = 0;

	while(s1[i] <= s1[n] || s1[i] == s2[j])
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
	printf("%d\n", ft_strncmp("kimwonkyun", "kimwon", 7));
	printf("%d\n", strncmp("kimwonkyun", "kimwon", 7));
	return 0;
}

