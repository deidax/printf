#include "main.h"
/**
 * print_char - Prints a character to the standard output.
 *
 * @args: args to be printed
 *
 * Description:
 *	This function prints a char
 */
void print_char(va_list args)
{
	char v;

	v = va_arg(args, int);
	_putchar(v);
}
/**
 * print_string - Prints a given string.
 *
 * @args: args to be printed
 *
 * Description:
 *     This function prints the given string to the standard output.
 */
void print_string(va_list args)
{
	char *v;

	v = va_arg(args, char *);
	if (v != NULL)
		_put(v);
}
