#include <stdio.h>

int	ft_atoi(char *str)
{
	int i;
	int minus;
	int num;
	
	i = 0;
	minus = 1;
	num = 0;

	while (str[i] == ' ' || str[i] == '\t' || str[i] == '\n' || str[i] == '\f' || str[i] == '\v' || str[i] == '\r')
		i++;
	while(str[i] == '-' || str[i] == '+')
	{
		if(str[i] == '-')
		{
			minus *= -1;
			i++;
		}
		else if(str[i] == '+')
			i++;
	}
	while(str[i] >= 48 && str[i] <= 57)
	{
		num = num * 10 + (str[i] - 48);
		i++;
	}	
	return (num * minus);
}

int	main(void)
{
	char arr[] = " -+1234";
	printf("%d", ft_atoi(arr));
	return 0;
}
//왜 0으로 나올까 결과가? 
// 마이너스가 들어가면 오류가 나온다. 
