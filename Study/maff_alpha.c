#include <unistd.h>

int	main(int argc, char **argv)
{
	int i;

	i = 0;
//	if (argc != '\0')
//	{
		if (i % 2 == 0)
		{
			if (argv[1][i] >= 'A' && argv[1][i] <= 'Z')
				argv[1][i] += 32;
		}
		else
			if (argv[1][i] >= 'a' && argv[1][i] <= 'z')
				argv[1][i] -= 32;
//	}
	return (0);
}
