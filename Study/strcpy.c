#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

int main()
{
	char s1[40];

	scanf("%s", s1);
	char s2[3] = "th";
	strcat(s1, s2);

	printf("%s\n", s1);
	return 0;
}
