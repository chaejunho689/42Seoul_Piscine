#include <stdio.h>

void	ft_sort_int_tab(int *tab, int size)
{
	int temp;
	int i;
	int j;

	i = 0;
	while (i < (size - 1))
	{
		j = 0;
		while (j < (size - 1))
		{
			if(tab[j] > tab[j + 1])
			{
				temp = tab[j];
				tab[j] = tab[j + 1];
				tab[j + 1] = temp;
			}
			j++;
		}
		i++;
	}
}

int		main(void)
{
		int arr[] = { 8, 4, -2, -2, 3, 1 };
		ft_sort_int_tab(arr, 6);
		for (int i = 0; i < 6; i++)
		{
			printf("%d ", arr[i]);
		}
		return 0;
}
