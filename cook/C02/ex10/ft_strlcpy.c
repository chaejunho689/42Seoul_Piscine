#include <stdio.h>
#include <string.h>

unsigned int ft_strlcpy(char *dest, char *src, unsigned int size)
{
	unsigned int i;
	unsigned int j;
	unsigned int result;

	i = 0;
	j = 0;
	while (src[j] != '\0')
	{
		j++;
	}
	result = j;
	j = 0;
	while ((src[j] != '\0') && (j < size + 1))
	{
		dest[i] = src[j];
		i++;
		j++;
	}
	dest[i] = '\0'; // 마지막에 널값 넣어주고
	return (result);
}

int 	main()
{
	char dest[] = "Hello";
	char src[] = "Annyong";
	char dest2[] = "Hello";
	char src2[] = "Annyong";
	printf("%d\n", ft_strlcpy(dest, src, 9));
	printf("%lu", strlcpy(dest2, src2, 5));
	return 0;
}
