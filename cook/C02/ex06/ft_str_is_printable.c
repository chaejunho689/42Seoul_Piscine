#include <stdio.h>

int        ft_str_is_printable(char *str)
{
    int i;
    int j;

    i = 0;
    if(str[0] == '\0')
    {
        j = 1;
    }
    while(str[i] != '\0')
    {
        if(32 <= str[i] && str[i] <= 126)
        {
            i++;
            j = 1;
        }
        else
        {
            j = 0;
            break;
        }
    }
    return (j);
}

int     main(void)
{
    char tab[6] = "ABC";
    ft_str_is_printable(&tab[0]);
    printf("%d", ft_str_is_printable(tab));
    return 0;
}

