#include "rush.h"

char zero[10] = "zero";
char hundreds[10] = "hundred";
char numbers[11][11] = {"", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};
char teen[11][11] = {"ten", "eleven", "twelve", "thirteen", "fourteen", "fifteen", "sixteen", "seventeen","eighteen", "nineteen"};
char tens[11][11] = {"","","twenty", "thirty", "forty", "fifty", "sixty", "seventy", "eighty", "ninety"};
char unit[15][15] = {"", "thousand", "million", "billion", "trillion"};

//malloc free를 할때 할당한 곳에서 free를 할 수 없다는 것은 다양한 함수에서 쓰인다는 것이고 그렇다면 global로 선언하여 접근을 용이하게하고 malloc free할때 빼놓은거 없이 할 수 있어서 global로 선언해도 된다고 생각함
uint8_t *g_input; 

uint8_t *input_to_int_arr(char *input, size_t input_len)
{
    uint8_t *num;
    int i, shift_num;  

    num = (uint8_t *)malloc_initialize(sizeof(uint8_t) * input_len);
    i = 0;
    shift_num = 0;
    if(input_len % 3)
        shift_num = 3 - (input_len % 3);
    while (input[i])
    {
        num[i + shift_num] = input[i] - '0';
        i++;
    }
    return num;
}

void print_term(int num)
{
    if(num/100 != 0)
    {
        ft_putchar_space(numbers[num/100]);
        ft_putchar_space(hundreds);
        num %= 100;
    }

    if(num/10 != 0)
    {
        if(num/10 == 1)
        {
            ft_putchar_space(teen[num%10]);
            return;
        }
        else
            ft_putchar_space(tens[num/10]);
        num %= 10;
    }

    if(num)
        ft_putchar_space(numbers[num]);
}

void print_numbers(size_t input_len)
{
    char *tmp_numstr;
    int i;
    int tmp_num;

    i = 0;
    while (i < input_len)
    {
        tmp_num = g_input[i]*100 + g_input[i+1]*10 + g_input[i+2];
        if(tmp_num > 0)
        {
            print_term(tmp_num);
            ft_putchar_space(unit[(input_len - 1 - i)/3]);
        }        
        i += 3;
    }
    write(1, "\n", 1);
}

int main(int argc, char **argv)
{
    size_t input_len;
    
    if (argc == 2)
    {
        input_len = ft_strlen(argv[1]);
        g_input = input_to_int_arr(argv[1], input_len);
    }
    else if (argc == 3)
    {
        return 1;
    }
    else
    {
        return 1;
    }
    print_numbers(input_len);
    return 0;
}