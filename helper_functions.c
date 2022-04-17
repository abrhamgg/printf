#include "main.h"
#include <stdio.h>
#include <stdbool.h>

/**
 * my_reverse - function tha reverse a string.
 * @str: input string.
 * @len: length of string.
 * Return: void.
 */

void my_reverse(char str[], int len)
{
	int start, end;
	char temp;

	for (start = 0, end = len - 1; start < end; start++, end--)
	{
		temp = *(str + start);
		*(str + start) = *(str + end);
		*(str + end) = temp;
	}
}

/**
 * my_itoa - function that converts strings to int.
 * @num: input value.
 * @str: output value.
 * @base: binary, hexa, octal.
 * Return: string.
 */

char *my_itoa(int num, char *str, int base)
{
	int i = 0;
	bool isNegative = false;

    /* A zero is same "0" string in all base */
	if (num == 0)
	{
		str[i] = '0';
		str[i + 1] = '\0';
		return (str);
	}
	if (num < 0 && base == 10)
	{
		isNegative = true;
		num = -num;
	}
	while (num != 0)
	{
		int rem = num % base;

		str[i++] = (rem > 9) ? (rem - 10) + 'A' : rem + '0';
		num = num / base;
	}
    /* Append negative sign for negative numbers */
	if (isNegative)
	{
		str[i++] = '-';
	}
	str[i] = '\0';
	my_reverse(str, i);
	return (str);
}
