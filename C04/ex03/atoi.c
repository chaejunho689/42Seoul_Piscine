#include<stdlib.h>
#include<stdio.h>
int main()
{
    int num = 0;
    char cStr[30] = "---++123ab123";
    
    printf("char* = %s\n", cStr);
    num = atoi(cStr);
 
    printf("int   = %d\n", num);
 
    system("pause");
    return 0;
}
