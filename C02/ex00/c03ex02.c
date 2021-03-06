#include <unistd.h>

char	ft_strcpy(char *dest, char *src)
{
	int i;
	int j;

	i = 0;
	j = 0;

	while (src[j] != '\0')
	{
		while (dest[i] != '\0')
		{
			
			i++;
		}
		j++;
	}
}

int main()
{
	char dest[] = {5, 6, 7, 8, 9};
	char src[] = {1, 2, 3, 4, 5};
	ft_strcpy(&dest[0], &src[0]);
	return 0;
}
