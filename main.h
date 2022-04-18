#ifndef MAIN
#define MAIN
#include <stdarg.h>
#include <stdlib.h>
#include <unistd.h>

/**
 * struct ops - a structure containing a char to compare with formatb modifiers
 * and then choose the right function when it matches
 * @operation: the char we want to compare to
 * @func: the address of the function we want to return if a char matches
 */

typedef struct ops
{
	char operation;
	int (*func)(va_list);
} ops_f;

int _printf(const char *format, ...);
int _putchar(char c);
int (*get_func(char ch))(va_list);
int print_nan(char ch1, char ch2);
int print_string(va_list list);
int print_char(va_list list);
int print_num(va_list list);
void my_reverse(char str[], int len);
char* my_itoa(int num, char* str, int base);
int print_binary(va_list list);
unsigned int base_len(unsigned int num, int base);
int print_unsigned(va_list list);
char *hex_conv(int num);
char *rev_string(char *s);
int print_hex(va_list list);
int print_Hex(va_list list);
int print_octal(va_list list);

#endif
