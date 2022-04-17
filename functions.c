#include "main.h"
#include <unistd.h>

/**
 *print_string - prints a string to stdout,1 char at a time
 *
 *@list:list to increment
 *
 *Return:no of char printed
 */

int print_string(va_list list)
{
	char *str;
	int i;
	char c;

	str = (va_arg(list, char *));
	if (str == NULL)
		str = "(null)";
	for (i = 0; str[i] != '\0'; i++)
	{
		c = str[i];
		write(1, &c, 1);
	}
	return (i);
}

/**
 * print_char - prints a char to stdout.
 * @list: list to increment.
 * Return: no of chars printed.
 */

int print_char(va_list list)
{
	char c;
	int i = 0;

	c = va_arg(list, int);
	if (c == '\0')
		return (-1);
	_putchar(c);
	i++;
	return (i);
}

/**
 * print_nan - writes chars after a % if they
 * don't match anything in the struct
 * @ch1: the first char passed (always %)
 * @ch2: the char after the %
 * Return: 1 if ch2 is a % and 2 is ch2 is anything else
 */

int print_nan(char ch1, char ch2)
{
	if (ch2 == '%')
	{
		write(1, &ch2, 1);
		return (1);
	}
	else
	{
		write(1, &ch1, 1);
		write(1, &ch2, 1);
		return (2);
	}
}
