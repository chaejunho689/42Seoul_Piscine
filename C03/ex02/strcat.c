#include <string.h>
#include <stdio.h>

char	*ft_strcat(char *dest, char *src)
{
	int i;
	int j;

	i = 0;
	j = 0;

	while(dest[i] != '\0')
	{
		i++;
	}
	while(src[j] != '\0')
	{
		dest[i] = src[j];
		i++;
		j++;
	}
	if(src[j] == '\0')
	{
		dest[i] = '\0';
	}
	return (dest);
}

#include <stdlib.h>

int 	main()
{	
	char *dest = malloc(sizeof(char) * 11); // 말록은 널값이 들어가야하므로 1 크기를 더 줌
	for (int i = 0; i < 5; i++)
		dest[i] = 'a';
	dest[5] = '\0';
	dest = ft_strcat(dest, "12345");
	printf("%s\n", dest);
	
	char *d2 = malloc(sizeof(char) * 11);
	for (int i = 0; i < 5; i++)
		d2[i] = 'b';
	d2[5] = '\0';
	dest = strcat(d2, "54321");
	printf("%s\n", d2);
	return 0;
}
