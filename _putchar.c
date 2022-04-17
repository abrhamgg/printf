#include "main.h"
#include <unistd.h>

/**
 * _putchar - fucntion that prints a char.
 * @c: input character.
 * Return: prints a char.
 */

int _putchar(char c)
{
	return (write(1, &c, 1));
}
