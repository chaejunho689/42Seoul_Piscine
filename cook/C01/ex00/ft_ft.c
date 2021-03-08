#include <unistd.h>
#include <stdio.h>

void	ft_ft(int *nbr)
{
	*nbr = 42;
}

int     main()
{
    int i;
    ft_ft(&i);
    printf("%d", i);
    return 0;
}
