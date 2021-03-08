#include <unistd.h>
#include <stdio.h>

char    *ft_strupcase(char *str)
{
    int i;

    i = 0;
    while (str[i] != '\0')
    {
        if (str[i] >= 'A' && str[i] <= 'Z')
        {
            str[i] += 32;
            i++;
        }
        else
            i++;
    }
    return (str);
}

int    main()
{
    int i = 0;
    char arr[15] = "-HelLLL-lo=";
    printf("%s", ft_strupcase(arr));
    return 0;
}
