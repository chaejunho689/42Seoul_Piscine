#include <unistd.h>
#include <stdio.h>
#include <string.h>

int	ft_strlen(char *s)
{
	int i;
	i = 0;

	while (*s != '\0')
	{
		s++;
		i++;
	}
	return (i);	
}

int	main(void)
{
	char s1[100];
	scanf("%s", s1);
	printf("%d\n", ft_strlen(s1));
//	printf("%lu\n", strlen(s1));
	return (0);
}
