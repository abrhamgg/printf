#include "main.h"
#include <stdio.h>
#include <stdlib.h>

/**
 *rev_string -reverses a string
 *@s:string to reverse
 *Return:pointer to reversed string
 */
char *rev_string(char *s)
{
	int i, max, half;
	char first, last;

	i = 0;
	while (s[i] != '\0')
	{
		i++;
	}
	max = i - 1;
	half = max / 2;

	while (half >= 0)
	{
		first = s[max - half];
		last = s[half];
		s[half] = first;
		s[max - half] = last;
		half--;
	}
	return (s);
}

/**
 *hex_conv - converts a number to any base specified by user
 *@num:number to convert
 *Return:pointer to converted string
 */
char *hex_conv(int num)
{
	char *str;
	int i, len;

	i = 0;
	len = base_len(num, 16);
	str = malloc((sizeof(char) * len) + 1);
	if (num == 0)
	{
		str[i] = 0;
	}
	i = 0;
	while (num > 0)
	{
		if ((num % 16) < 10)
		{
			str[i] = (num % 16) + 48;
			i++;
		}
		else
		{
			str[i] = (num % 16) + 55;
			i++;
		}
		num /= 16;
	}
	rev_string(str);
	return (str);
}
/**
 *print_octal - prints a number in octal
 *@list:list to increment
 *Return:no. of characters printed
 */
int print_octal(va_list list)
{
	unsigned int num;
	int i, j, len;
	char *str;

	num = va_arg(list, unsigned int);

	if (num == 0)
	{
		_putchar('0');
		return (1);
	}
	len = base_len(num, 8);
	str = malloc((sizeof(char) * len) + 1);
	if (str == NULL)
	{
		return (-1);
	}
	i = 0;
	while (num > 0)
	{
		str[i] = num % 8;
		num = num / 8;
		i++;
	}
	for (j = (i - 1); j >= 0; j--)
	{
		_putchar(str[j] + '0');
	}
	free(str);
	return (len);
}
/**
 *print_Hex - prints unsigned int in Hex upper format
 *@list:list to increment
 *Return:no. of characters printed
 */
int print_Hex(va_list list)
{
	unsigned int num;
	int i, j, temp, len;
	char *str;

	num = va_arg(list, unsigned int);
	if (num == 0)
	{
		_putchar('0');
		return (1);
	}
	len = base_len(num, 16);
	str = malloc((sizeof(char) * len) + 1);
	if (str == NULL)
	{
		return (-1);
	}
	i = 0;
	while (num > 0)
	{
		temp = num % 16;
		if (temp < 10)
		{
			str[i] = temp + 48;
			i++;
		}
		else
		{
			str[i] = temp + 55;
			i++;
		}
		num = num / 16;
	}
	for (j = (i - 1); j >= 0; j--)
	{
		_putchar(str[j]);
	}
	free(str);
	return (len);
}
/**
 *print_hex - prints unsigned int in hex lower format
 *@list:list to increment
 *Return:no. of characters printed
 */
int print_hex(va_list list)
{
	unsigned int num;
	int i, j, temp, len;
	char *str;

	num = va_arg(list, unsigned int);
	if (num == 0)
	{
		_putchar('0');
		return (1);
	}
	len = base_len(num, 16);
	str = malloc((sizeof(char) * len) + 1);
	if (str == NULL)
	{
		return (-1);
	}
	i = 0;
	while (num > 0)
	{
		temp = num % 16;
		if (temp < 10)
		{
			str[i] = temp + 48;
			i++;
		}
		else
		{
			str[i] = temp + 87;
			i++;
		}
		num = num / 16;
	}
	for (j = (i - 1); j >= 0; j--)
	{
		_putchar(str[j]);
	}
	free(str);
	return (len);

}
