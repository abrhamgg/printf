#include "main.h"
#include <unistd.h>
#include <stdarg.h>
#include <stdbool.h>

/**
 * my_reverse - function that reverse a string.
 * @str: string to be reversed.
 * @len: length of the string.
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
 * my_itoa - function that convert an integer to string.
 * @num: input integer.
 * @str: output string.
 * @base: hexa octa or deci.
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
/**
 * _strlen - fucntion that calculates the length of the string.
 * @str: - input value.
 * Return: number of chars.
 */
int _strlen(char *str)
{
	int i = 0;
	int len = 0;

	while (str[i] != '\0')
	{
		i++;
		len++;
	}
	return (len);
}

/**
 * _printf - custom made printf function.
 * @format: input value.
 * @...: argument.
 * Return: total number char printed.
 */
int _printf(const char *format, ...)
{
	int i, j, count = 0;
	char *str;
	va_list ptr;

	va_start(ptr, format);
	for (i = 0; format[i] != '\0'; i++)
	{
		if (format[i] == '%' && format[i + 1] == 'c')
		{
			j = va_arg(ptr, int);
			_putchar(j);
			count++;
			i = i + 1;
		}
		if (format[i] == '%' && format[i + 1] == 's')
		{
			str = va_arg(ptr, char *);
			_puts(str);
			count = count + _strlen(str) - 1;
			i += 1;
		}
		if (format[i] == '%' && (format[i + 1] == 'd' || format[i + 1] == 'i'))
		{
			/**convert - turns an int to a string.*/
			int nm = va_arg(ptr, int);
			char ch[128];

			my_itoa(nm, ch, 10);

			_puts(ch);
			count = count + _strlen(ch) - 1;
			i = i + 1;
		}
		else
		{
			_putchar(format[i]);
			count++;
		}
	}
	va_end(ptr);
	return (count);
}
