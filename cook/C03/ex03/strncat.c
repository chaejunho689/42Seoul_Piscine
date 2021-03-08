#include <string.h>
#include <stdio.h>

char	*ft_strncat(char *dest, char *src, unsigned int nb)
{
	unsigned int i;
	unsigned int j;

	i = 0;
	j = 0;

	while(dest[i] != '\0')
	{
		i++;
	}
	while(src[j] != '\0' && j < nb)
	{
		dest[i] = src[j];
		i++;
		j++;
	}
	dest[i] = '\0';
	return (dest);
}

int 	main()
{	
	char dest[100] = "Hello";
	char src[7] = "Annyong";
	printf("%s\n", ft_strncat(dest, src, 3));
	char pest[10] = "Hello";
	printf("%s\n", strncat(pest, src, 3));
	return 0;
}


