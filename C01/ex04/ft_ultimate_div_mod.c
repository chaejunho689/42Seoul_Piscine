#include <stdio.h>
#include <unistd.h>

void	ft_ultimate_div_mod(int *a, int *b)
{
	int mok;
	int namuji;

	mok = *a / *b;
	namuji = *a % *b;

	*a = mok;
	*b = namuji;
}

int	main(void)
{
	int a;
	int b;
	a = 20;
	b = 2;

	ft_ultimate_div_mod(&a, &b);
	printf("%d %d", a, b);
	return (0);
}
