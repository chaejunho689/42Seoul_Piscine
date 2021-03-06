#include <stdio.h>
#include <string.h>

unsigned int	ft_strlcat(char *dest, char *src, unsigned int size)
{
	int i;
	int j;
	int result;
	int dest_size;
	int src_size;

	i = 0;
	j = 0;

	while(dest[i] != '\0')
	{
		i++;
		dest_size = i;
	}
	while(src[j] != '\0')
	{
		j++;
		src_size = j;
	}
	while(src[j] != '\0' && j < (size -1))
	{
		dest[i] = src[j];
		i++;
		j++;
	}
	dest[i] = '\0';
	if(size < dest_size)
		result = src_size + size;
	else if(size > dest_size)
		result = src_size + dest_size;
	else
		result = dest_size + src_size;
	return (result);
}

int	main()
{
	char dest[10] = "Hell"; //4개
	char src[] = "An"; //2개
	printf("%lu", strlcat(dest, src, 4));
	printf("%s", dest);
//	printf("%d", ft_strlcat(dest, src, 4));
	return 0;
}
