#include <stdio.h>
#include <string.h>

int				ft_strlen(char *str)
{
	int i;
    
	i = 0;
	while (str[i] != '\0')
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

	src_size = 0;
	dest_size = ft_strlen(dest);
	save_src_size = ft_strlen(src);
	save_dest_size = ft_strlen(dest);
	j = size - dest_size - 1;
	if (save_dest_size < size)
	{
		while ((src[src_size] != '\0') && (src_size < j))
		{
//										printf("i랑 j값 %d %d\n", i, j);
//										printf("소스 사이즈 %c\n", src[src_size]);
			dest[dest_size++] = src[src_size++];
//			dest_size++;
//			src_size++;
		}
		dest[dest_size + 1] = '\0';
		return (save_src_size + save_dest_size);
	}
	else
		return (save_src_size + size);
}

int    main()
{
	char dest[10] = "123";
	char src[] = "123123";
	printf("정답" "%lu %s\n", strlcat(dest, src, 5), dest); // 실제
	char dest2[10] = "123";
	char src2[] = "123123";
	printf("풀이" "%d %s\n", ft_strlcat(dest2, src2, 5), dest2); // 구현
	return 0;
}

