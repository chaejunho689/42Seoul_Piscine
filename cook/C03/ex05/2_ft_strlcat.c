#include <stdio.h>
#include <string.h>

int	ft_strlen(char *str)
{
	int i;

	i = 0;
	while(str[i] != '\0')
	{
		i++;
	}
	return (i);
}

unsigned int	ft_strlcat(char *dest, char *src, unsigned int size)
{
	unsigned int dest_size;
	unsigned int src_size;
	unsigned int j;
	unsigned int save_src_size;
	unsigned int save_dest_size;

	j = size;	
	dest_size = ft_strlen(dest);
	src_size = ft_strlen(src);
	save_src_size = src_size;
	save_dest_size = dest_size;
	if (dest_size <= size)
	{
		src_size = 0;
		while ((src[src_size] != '\0') && (j > 0))
		{
			dest[dest_size] = src[src_size];
			dest_size++;
			src_size++;
			j--;
		}
		dest[dest_size] = '\0';
//		printf("디버깅 src size" "%d", src_size);
		return (save_src_size + save_dest_size);
	}
	else
	{
		return (save_src_size + size);
//	return (save_src_size + size);
	}
}

int    main()
{
	char dest[10] = "Helle";
	char src[] = "123456789";
	printf("정답" "%lu\n", strlcat(dest, src, 1)); // 실제
//	printf("%s", dest);
//	printf("%s " , dest);
//	printf("%s " , src);
	char dest2[10] = "Helle";
	char src2[] = "123456789";
	printf("내꺼" "%d\n", ft_strlcat(dest2, src2, 1)); // 구현
	return 0;
}

