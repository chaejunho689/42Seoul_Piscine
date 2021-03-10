#include <stdio.h>
#include <string.h>


unsigned int 	ft_result(int dest_size, int src_size, int size)
{
	unsigned int result;

	if(size <= dest_size)
		result = src_size + size;
	else
		result = src_size + dest_size;
	return (result);
}


unsigned int	ft_strlcat(char *dest, char *src, unsigned int size)
{
	unsigned int result;
	unsigned int dest_size;
	unsigned int src_size;

	result = 0;
	dest_size = 0;
	src_size = 0;
	while (dest[dest_size] != '\0')
		dest_size++;
	while (src[src_size] != '\0')
		src_size++;
	result = ft_result(dest_size, src_size, size);
	while ((src[src_size] != '\0') && (size - dest_size - 1))
	{
		dest[dest_size] = src[src_size];
		dest_size++;
		src_size++;
	}
	dest[dest_size] = '\0';
	return (result);
}

int	main()
{
	char dest[10] = "Helleee"; //4개
	char src[] = "Anaaa"; //2개
	printf("%lu", strlcat(dest, src, 8));
//	printf("%s", dest);
	char dest2[10] = "Helleee";
	char src2[] = "Anaaa";
	printf("%d", ft_strlcat(dest2, src2, 8));
	return 0;
}
