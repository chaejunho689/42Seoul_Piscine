#include <stdio.h>
#include <string.h>


unsigned int 	ft_result(int dest_size, int src_size, int size)
{
	int result;
	if(size <= dest_size)
		result = src_size + size;
	else if(size > dest_size)
		result = src_size + dest_size;
	else
		result = dest_size + src_size;
	return (result);
}


unsigned int	ft_strlcat(char *dest, char *src, unsigned int size)
{
	unsigned int result;
	unsigned int dest_size;
	unsigned int src_size;

	dest_size = 0;
	src_size = 0;
	while (dest[dest_size] != '\0')
		dest_size++;
	while (src[src_size] != '\0')
		src_size++;
	dest[dest_size] = '\0';
	while
	return (ft_result(dest_size, src_size, size));
/*
	if(size < dest_size)
		result = src_size + size;
	else if(size > dest_size)
		result = src_size + dest_size;
	else
		result = dest_size + src_size;
	return (result);
*/

}

int	main()
{
	char dest[10] = "Hell"; //4개
	char src[] = "Anaaa"; //2개
	printf("%lu", strlcat(dest, src, 9));
//	printf("%s", dest);
	printf("%d", ft_strlcat(dest, src, 9));
	return 0;
}
