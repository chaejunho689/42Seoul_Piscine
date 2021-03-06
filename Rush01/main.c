#include <stdio.h>

char	**ft_split(char *str);
void	rush(char *str);

int		main(int argc, char *argv[])
{
//	char	**result;

	if (argc != 2)
		return (0);
//	result = ft_split(argv[1]);
//
//	while (*result)
//	{
//		printf("%s\n", *result);
//		result++;
//	}

	rush(argv[1]);

	return (0);
}
