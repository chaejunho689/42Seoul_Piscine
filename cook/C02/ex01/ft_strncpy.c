#include <stdio.h>

char 	*ft_strncpy(char *dest, char *src, unsigned int n)
{
	n = 0;
	while (src[n] != '\0')
	{
		dest[n] = src[n];
		n++;
	}
	return (dest);
}

int	main(void)
{
	char dest[7] = "Hello";
	char src[4] = "hi";
	ft_strncpy(dest, src);
	printf("%s", dest);
	return 0;
}
