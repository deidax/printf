#include "main.h"
/**
 * print_char - Prints a character to the standard output.
 *
 * @args: args to be printed
 *
 * Description:
 *	This function prints a char
 *
 * Return:
 *	number of characters printed
 */
int print_char(va_list args)
{
	char v;
	int count = 0;

	v = va_arg(args, int);
	count = _putchar(v);
	_putchar('\n');
	return (count);
}
/**
 * print_string - Prints a given string.
 *
 * @args: args to be printed
 *
 * Description:
 *     This function prints the given string to the standard output.
 *
 * Return:
 * 	number of characters printed
 */
int print_string(va_list args)
{
	char *v;
	int count = 0;

	v = va_arg(args, char *);
	if (v != NULL)
	{
		count = _put(v);
		_put("\n");
		return (count - 1);
	}
	return (0);
}
