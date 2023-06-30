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
 *	number of characters printed
 */
int print_string(va_list args)
{
	char *v;
	int count = 0;
	char *null = "(null)";

	v = va_arg(args, char *);
	if (v != NULL)
	{
		while (*v != '\0')
		{
			count += _putchar(*v);
			v++;
		}
	}
	else
	{
		while (*null != '\0')
		{
			count += _putchar(*null);
			null++;
		}
	}
	return (count);
}
/**
 * print_percentage - Prints a percentage character.
 *
 * @args: args to be printed
 *
 * Description:
 *     This function prints the percentage symbol.
 *
 * Return:
 *      number of characters printed
 */
int print_percentage(va_list args)
{
	(void) args;

	_putchar('%');
	return (1);
}
/**
 * print_empty - Prints an empty character.
 * @args: The argument list (unused).
 *
 * Description:
 *      The print_empty function is used to print an empty character ('\0')
 *      to the standard output. The argument list is unused in this function.
 *      It returns -1 to indicate an error since printing an empty character
 *      has no practical use.
 *
 * Return:
 *      -1 to indicate an error.
 */
int print_empty(va_list args)
{
	(void) args;

	_putchar('\0');
	return (-1);
}
/**
 * print_special - Handles the custom conversion specifier 'S'.
 * @args: The va_list containing the argument to be printed.
 *
 * Description:
 *     The print_special function is responsible for handling the
 *     custom conversion specifier 'S'. It takes a va_list containing the
 *     argument to be printed and handles the formatting accordingly.
 *     If the argument contains non-printable characters (ASCII value between
 *     0 and 31 or greater than or equal to 127), it prints them as \x followed
 *     by the ASCII code value in uppercase hexadecimal format (always 2
 *     characters).
 *
 * Return:
 *     The total number of characters printed.
 */
int print_special(va_list args)
{
	char *v;
	int count = 0;

	v = va_arg(args, char *);
	if (v != NULL)
	{
		while (*v != '\0')
		{
			count += print_special_helper(*v);
			v++;
		}
	}
	else
		_printf("(null)");
	return (count);
}
