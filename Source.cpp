#include <stdio.h>
#include "Header.h"

int main() {

	char str[256];
	printf("strlen test:\nEnter string: ");
	gets_s(str);
	int len = my_strlen(str);
	printf("String length: %d\n", len);

	char str1[256];
	char str2[256];
	printf("String copy test:\nEnter first string: ");
	gets_s(str1);
	printf("Enter second string: ");
	gets_s(str2);
	my_strcpy(str1, str2);
	printf("first string: %s\nsecond string: %s\n", str1, str2);

	printf("String unification test:\nEnter first string: ");
	gets_s(str1);
	printf("Enter second string: ");
	gets_s(str2);
	my_strcat(str1, str2);
	printf("first string: %s\nsecond string: %s\n", str1, str2);

	printf("String comparation test:\nEnter first string: ");
	gets_s(str1);
	printf("Enter second string: ");
	gets_s(str2);
	int diff = my_strcmp(str1, str2);
	printf("%d\n", diff);

	printf("Symbol search test:\nEnter string: ");
	gets_s(str);
	printf("Enter symbol: ");
	int c;
	scanf_s("%c", &c);
	char* chr = my_strchr(str, c);
	printf("%s\n", chr);

	printf("String in a string search test:\nEnter first string: ");
	gets_s(str1);
	printf("Enter second string: ");
	gets_s(str2);
	char* chr1 = my_strstr(str1, str2);
	printf("%s\n", chr1);

	return 0;
}