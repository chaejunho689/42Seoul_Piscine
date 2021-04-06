#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int	main(void)
{
	char *str;
	int space;

	space = 0;

	str = malloc(sizeof(char) * 1000);
	scanf("%[^\n]s", str);

	while (*str != 0)
	{
		if (*str == ' ')
		{
			space++;
			str++;
		}
		else
			str++;
	}
	printf("%d", space);
	return (0);
}
