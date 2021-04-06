#include <unistd.h>

/*
int	main(void)
{
	write(1, "9876543210", 10)
	reutrn (0);
}
*/

int	main(void)
{
	char c;

	c = '9';
	while (c >= '0')
	{
		write(1, &c, 1);
		c--;
	}
	return (0);
}	
