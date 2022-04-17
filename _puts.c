#include "main.h"
#include <stdio.h>

/**
 * _puts - function that prints a string.
 * @str: input string.
 * Return: number of chars printed.
 */

int _puts(char *str)
{
	int i;
	int len = 0;

	for (i = 0; str[i] != '\0'; i++)
	{
		_putchar(str[i]);
		len++;
	}
	return (len);
}
