#include <stdio.h>
#include <string.h>


unsigned int 	ft_result(unsigned int dest_size, unsigned int src_size, unsigned int size)
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
	while (dest[dest_size] != '\0') // 길이 측정
		dest_size++;
	while (src[src_size] != '\0') // 길이 측정
		src_size++;
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
	char src[] = "123456789"; //2개
	printf("%lu\n", strlcat(dest, src, 8));
//	printf("%s", dest);
	printf("%s " , dest);
	printf("%s " , src);
	char dest2[10] = "Helleee";
	char src2[] = "123456789";
	printf("%d\n", ft_strlcat(dest2, src2, 8));
	return 0;
}
