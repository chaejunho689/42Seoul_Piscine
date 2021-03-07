#include <unistd.h>

unsigned int ft_strlcpy(char *dest, char *src, unsigned int size)
{
	int i;
	int j;

	i = 0;
	j = 0;

	while(dest[i] != '\0')
	{
		i++;
	}
	while(src[j] != '\0' && j < size)
	{
		dest[i] = src[j];
		j++;
	}
}

int 	main()
{

	return 0;
}
